"""Turn key sequences into C code from web page."""
from bs4 import BeautifulSoup
import requests

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


def tag_to_title(tag: str):
    """Get value between quote " marks"""
    return tag.split('title="')[-1].split('"')[0].removesuffix(" (page does not exist)")


def _key_map_generator(stratagems: dict[str, list[str]]):
    c_code = ""
    for title, seq in stratagems.items():
        sequence = " ".join(seq)
        branch = "\n".join(
            [
                f"case {title.replace(' ', '_').replace('-','_').replace('/','').upper()}:",
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


def _custom_key_codes(stratagems: dict[str, list[str]]):
    c_code = ""
    for title in stratagems.keys():
        c_code = (
            c_code
            + title.replace(" ", "_").replace("-", "_").replace("/", "").upper()
            + ",\n"
        )
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

    print(_custom_key_codes(stratagems))
    print(_key_map_generator(stratagems))


if __name__ == "__main__":
    main()
