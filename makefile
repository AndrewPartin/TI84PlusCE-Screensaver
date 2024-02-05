# ----------------------------
# Makefile Options
# ----------------------------

NAME = TROLL
ICON = icon.png
DESCRIPTION = "Sprite test"
COMPRESSED = NO
ARCHIVED = NO

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
