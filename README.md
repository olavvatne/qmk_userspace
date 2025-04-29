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
qmk c2json ./keyboards/crkbd/keymaps/seniply/keymap.c
```
