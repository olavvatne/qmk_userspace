# QMK Userspace

Personal keyboard QMK keymaps. Based on seniply, home row mod like miryoku

## Setup

```python
brew install qmk/qmk/qmk
qmk setup
qmk compile -kb crkbd/rev1 -km seniply
```

## Loading firmware to Corne

* Connect keyboard to computer, double tap reset button.
* Drag&drop firmware to external drive

## Setting up a new keyboard

See [qmk_userspace repo](https://github.com/qmk/qmk_userspace)

## Commands

```bash
qmk c2json ./keyboards/crkbd/rev1/keymaps/seniply/keymap.c
```

## Generating svg of your keymap

Navigate to your custom qmk setup, and:

```bash
python -m venv .venv 
source .venv/bin/activate
pip install keymap-drawer
qmk c2json ./keyboards/crkbd/rev1/keymaps/seniply/keymap.c | keymap parse --layer-names Base Extend Symbol Number Function  -c 12 -q - > keymap.yaml
keymap draw keymap.yaml --select-layers Base > keymap.base.svg
keymap draw keymap.yaml --select-layers Extend > keymap.extend.svg
keymap draw keymap.yaml --select-layers Symbol > keymap.symbol.svg
keymap draw keymap.yaml --select-layers Number > keymap.number.svg
keymap draw keymap.yaml --select-layers Function > keymap.function.svg
```

