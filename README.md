<div align="center">

  <h1>Sorting Algorithms Visualizer</h1>

  <p>
    <b>A C/SDL2 desktop visualizer that turns sorting algorithms into step-by-step animated state machines.</b>
  </p>

  <p>
    <img alt="C" src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" />
    <img alt="SDL2" src="https://img.shields.io/badge/SDL2-173B6B?style=for-the-badge&logo=libsdl&logoColor=white" />
    <img alt="SDL2 TTF" src="https://img.shields.io/badge/SDL2_ttf-7C3AED?style=for-the-badge" />
    <img alt="Algorithms" src="https://img.shields.io/badge/Algorithms-FF006E?style=for-the-badge" />
    <img alt="Visualization" src="https://img.shields.io/badge/Visualization-FFB703?style=for-the-badge" />
  </p>

  <p>
    <a href="#features">
      <img alt="Features" src="https://img.shields.io/badge/Features-00C2A8?style=for-the-badge" />
    </a>
    <a href="#algorithms">
      <img alt="Algorithms" src="https://img.shields.io/badge/Algorithms-7C3AED?style=for-the-badge" />
    </a>
    <a href="#architecture">
      <img alt="Architecture" src="https://img.shields.io/badge/Architecture-FF3864?style=for-the-badge" />
    </a>
    <a href="#controls">
      <img alt="Controls" src="https://img.shields.io/badge/Controls-F59E0B?style=for-the-badge" />
    </a>
  </p>

</div>

---

## Overview

**Sorting Algorithms Visualizer** is an SDL2 desktop app that renders an array of `105` values as vertical bars and advances the selected sorting algorithm one operation at a time.

Instead of hiding the work inside a single blocking sort call, every algorithm stores its progress in a small state struct. That makes comparisons, swaps, pivots, sorted regions, merge phases, and unfinished regions visible frame by frame.

## Features

<table>
  <tr>
    <td><b>Five algorithms</b></td>
    <td>Bubble, selection, insertion, merge, and quick sort.</td>
  </tr>
  <tr>
    <td><b>Step-based execution</b></td>
    <td>Each frame advances the active sort by a small visible operation.</td>
  </tr>
  <tr>
    <td><b>Color-coded bars</b></td>
    <td>Highlights comparisons, active pointers, pivots, sorted sections, and unfinished data.</td>
  </tr>
  <tr>
    <td><b>Clickable controls</b></td>
    <td>Start, stop/reset, choose algorithms, and randomize the array from the SDL UI.</td>
  </tr>
  <tr>
    <td><b>State-machine recursion</b></td>
    <td>Merge sort and quick sort use explicit stacks so recursive behavior can be animated.</td>
  </tr>
  <tr>
    <td><b>Fixed render target</b></td>
    <td>Uses a clean <code>1280x720</code> window with consistent bar spacing.</td>
  </tr>
</table>

## Algorithms

| Algorithm | What the visualizer exposes |
| --- | --- |
| Bubble sort | Adjacent comparisons, swaps, and the growing sorted tail. |
| Selection sort | Scan pointer, current minimum, and completed prefix. |
| Insertion sort | Insert key, shifting region, and sorted prefix. |
| Merge sort | Split stack, active merge pointers, temporary buffer, and copy-back phase. |
| Quick sort | Partition stack, pivot, scan pointer, and partitioned subranges. |

## Tech Stack

<p>
  <img alt="C" src="https://img.shields.io/badge/C-0B5FFF?style=flat-square&logo=c&logoColor=white" />
  <img alt="SDL2" src="https://img.shields.io/badge/SDL2-1F6FEB?style=flat-square&logo=libsdl&logoColor=white" />
  <img alt="SDL2 ttf" src="https://img.shields.io/badge/SDL2_ttf-9B5DE5?style=flat-square" />
  <img alt="SDL2 image" src="https://img.shields.io/badge/SDL2_image-F97316?style=flat-square&logo=image&logoColor=white" />
  <img alt="SDL2 mixer" src="https://img.shields.io/badge/SDL2_mixer-06B6D4?style=flat-square" />
  <img alt="GCC" src="https://img.shields.io/badge/GCC-111827?style=flat-square&logo=gnu&logoColor=white" />
</p>

| Layer | Technology | Role |
| --- | --- | --- |
| Language | `C` | Algorithm state, array data, event loop, and render logic. |
| Rendering/UI | `SDL2` | Window, renderer, input events, rectangles, and frame updates. |
| Text | `SDL2_ttf` | Button labels and UI text rendering. |
| Headers linked | `SDL2_image`, `SDL2_mixer` | Included/linked for SDL project consistency. |
| Compiler | `GCC` / `Clang` | Native build toolchain. |

## Project Structure

```text
.
|-- main.c       # SDL window, event loop, UI controls, bar rendering
|-- fonctions.c  # Sorting state machines and utility logic
|-- headers.h    # SDL includes, structs, and function prototypes
|-- font.ttf     # Local font asset
|-- prot         # Existing compiled/development artifact
`-- README.md    # Project documentation
```

## Architecture

```text
main.c
|-- owns SDL window, renderer, event loop, buttons, and bar drawing
|-- owns the shared table[105] array
|-- chooses which algorithm state machine runs each frame
`-- converts algorithm state into bar colors

fonctions.c
|-- bubble()     -> advances one bubble-sort step
|-- selection()  -> advances one selection-sort step
|-- insert()     -> advances one insertion-sort step
|-- merge()      -> advances merge-sort stack/subphase state
|-- quick()      -> advances quick-sort partition stack
`-- resetem()    -> resets all algorithm structs and active flags

headers.h
|-- SDL includes
|-- algorithm state structs
`-- function declarations
```

The core design choice is that no algorithm runs to completion in one call. Every sort is represented as a resumable state machine. `main.c` calls one step, draws the array, waits briefly, then repeats. That keeps SDL responsive and makes the internal algorithm state visible.

## Build

Install SDL2 development packages on Ubuntu/Debian:

```bash
sudo apt install build-essential libsdl2-dev libsdl2-ttf-dev libsdl2-image-dev libsdl2-mixer-dev
```

Compile from the repository root:

```bash
gcc main.c fonctions.c -o sorter \
  -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -lm
```

## Run

```bash
./sorter
```

The application opens a fixed `1280x720` SDL2 window.

## Controls

| Control | Action |
| --- | --- |
| `start` | Starts the currently selected algorithm. |
| `stop` | Resets the algorithm state. |
| `bubble` | Selects bubble sort. |
| `selection` | Selects selection sort. |
| `insert` | Selects insertion sort. |
| `merge` | Selects merge sort. |
| `quick` | Selects quick sort. |
| `reset ts` | Generates a new random array and resets the visualizer. |
| Window close | Quit the app. |

## How It Works

### 1. Data Model

The visualizer stores the working data in:

```c
int table[105];
```

Each value becomes a vertical bar. Heights are randomized in the range `100..520`, then drawn from the bottom of the window upward.

### 2. Algorithm State

Each algorithm has a dedicated struct:

| Struct | Algorithm |
| --- | --- |
| `bubbly` | Bubble sort |
| `selecty` | Selection sort |
| `inserty` | Insertion sort |
| `mergy` | Merge sort |
| `quicky` | Quick sort |

Those structs store indexes, pivots, phases, stack positions, temporary arrays, and finished flags. The render loop calls only the active algorithm, then redraws every bar with colors based on that algorithm's current state.

### 3. Recursive Algorithms Without Blocking

Merge sort and quick sort are normally recursive, but this visualizer makes them frame-friendly:

| Algorithm | Strategy |
| --- | --- |
| Merge sort | Uses an explicit `stackbox stack[200]`, phases, subphases, and a temporary buffer. |
| Quick sort | Uses an explicit `stacky std[200]`, partition phases, pivot tracking, and subrange pushes. |

That design keeps the SDL event loop alive while recursive behavior is still visible.

### 4. Color Language

The colors are used as runtime signals:

| Color | Meaning |
| --- | --- |
| Green | Sorted or completed region. |
| Blue | Active comparison/index/pointer. |
| Red | Unsorted or pivot-related area depending on algorithm. |
| Black | Merge/insert intermediate region or inactive bars. |

## Why I Built This

> Write your personal note here.

Suggested direction:

```md
I built this because sorting algorithms are easy to memorize but harder to truly see.
Turning each algorithm into a state machine made the steps visible: comparisons, swaps,
pivots, stack phases, and the moment the array finally becomes ordered.
```

## Current Status

| Area | Status |
| --- | --- |
| Bubble sort | Working |
| Selection sort | Working |
| Insertion sort | Working |
| Merge sort | Working |
| Quick sort | Working |
| Randomized arrays | Working |
| Clickable SDL controls | Working |

## Known Limitations

| Limitation | Current state |
| --- | --- |
| Window layout | Fixed around `1280x720`. |
| Array size | Fixed at `105` bars. |
| UI positions | Button positions and labels are hard-coded. |
| Font path | `main.c` currently opens a system Liberation Serif font path. |
| Speed control | Delay is fixed with `SDL_Delay(10)`. |

## Roadmap Ideas

| Idea | Why it would help |
| --- | --- |
| Speed slider | Compare algorithms at different animation speeds. |
| Array size control | Show how algorithms behave on smaller or larger datasets. |
| Comparison/swap counters | Add quantitative feedback beside the animation. |
| Better color legend | Make the meaning of each highlight visible in-app. |
| Cleaner build script | Make compilation easier across machines. |

---

<div align="center">
  <sub>Built with C, SDL2, algorithm state structs, and frame-by-frame sorting.</sub>
</div>
