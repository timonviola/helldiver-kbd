"""Turn key sequences into C code from web page."""
from bs4 import BeautifulSoup
import requests
import json

ARROW_MAP = {
    "Arrow_1": "_S",
    "Arrow_2": "_A",
    "Arrow_3": "_D",
    "Arrow_4": "_W",
}


def get_arrow(tag: str):
    tag = str(tag)
    for k in ARROW_MAP.keys():
        if k in tag:
            return ARROW_MAP[k]
    raise KeyError


def a_tag_to_arrow(tag: str):
    sequence = []
    a_tags = str(tag).split("<a")
    for a in a_tags:
        try:
            sequence.append(get_arrow(a))
        except KeyError:
            continue
    return sequence


def generate_vial_codes(stratagems: dict[str, list[str]]) -> str:
    """Generate vial.json custom key code descriptions.

    The output is a json list, with should is manually
    copied into vial.json.

    The generated list:
      - MUST match the contents of the `enum` in length and order
        See: _custom_key_codes

    Reference: https://get.vial.today/docs/custom_keycode.html"""

    def get_keycode_entry(title: str) -> dict[str, str]:
        """Create custom key code object prototype."""
        stratagem_code = create_stratagem_code(title)
        return {
            # name shown in vial UI
            "name": title if len(title) <= 5 else title[:5].rstrip(),
            # show title on hover in vial UI
            "title": title.replace('_', ' ').title(),
            # code in key map
            "shortName": stratagem_code
        }

    custom_keycodes:list[dict[str,str]] = []
    for title in stratagems.keys():
        custom_keycodes.append(get_keycode_entry(title))

    return json.dumps(custom_keycodes, indent=2)


def tag_to_title(tag: str):
    """Get value between quote " marks"""
    return tag.split('title="')[-1].split('"')[0].removesuffix(" (page does not exist)")


def create_stratagem_code(c: str) -> str:
    return c.replace(" ", "_").replace("-", "_").replace("/", "").upper()


def _key_map_generator(stratagems: dict[str, list[str]]):
    c_code = ""
    for title, seq in stratagems.items():
        sequence = " ".join(seq)
        branch = "\n".join(
            [
                f"case {create_stratagem_code(title)}:",
                f"  if (record->event.pressed) {{",
                f"    SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) {sequence} SS_UP(X_LCTL) SS_DELAY(35) _MB1);",
                f"  }} else {{",
                "",
                f"  }}",
                f"  break;\n",
            ]
        )
        c_code = c_code + branch
    return c_code


def _custom_key_codes(stratagems: dict[str, list[str]], *, suffix=" = QK_KB_0"):
    """Each stratagem gets a custom key code.

    These values are used to populate an enum at the top of the keymap file.
    - The first entry has to be suffixed with ` = QK_KB_0`

    """
    c_code = ""
    is_first_code = True
    for title in stratagems.keys():
        if is_first_code:
            is_first_code = False
            c_code = c_code + create_stratagem_code(title) + suffix + ",\n"
            continue
        
        c_code = c_code + create_stratagem_code(title) + ",\n"
    return c_code


def main():
    # URL of the HTML page
    url = "https://helldivers.fandom.com/wiki/Stratagem_Codes_(Helldivers_2)"

    # Send a GET request to the URL
    response = requests.get(url)

    # Parse the HTML content
    soup = BeautifulSoup(response.content, "html.parser")

    # Find all tables on the webpage
    tables = soup.find_all("table")

    # Iterate over each table
    stratagems = {}
    for table in tables:
        # Find all rows in the table
        rows = table.find_all("tr")
        for row in rows:
            # Extract data from each cell in the row
            cells = row.find_all(["td", "th"])
            if len(cells) == 6 and "title" in str(cells[1]):
                tit = tag_to_title(str(cells[1]))
                seq = a_tag_to_arrow(cells[2])
                stratagems[tit] = seq

    # sort by key name for human searchability
    stratagems = dict(sorted(stratagems.items()))
    print(_custom_key_codes(stratagems))
    print(generate_vial_codes(stratagems))
    print(_key_map_generator(stratagems))


if __name__ == "__main__":
    main()
