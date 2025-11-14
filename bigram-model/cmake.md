why do we have a single include directory for both app and src?


That's an excellent question, Vrindavan, and it gets to the very heart of good C project design and "separation of concerns."

The short answer is: **We don't.**

Let's re-frame the purpose of that `include/` directory. It's not a "shared folder" for both `app` and `src` to dump things into.

Instead, think of it as the **Public API**, or the **"contract,"** of your library.

* The **`src/`** directory (your library) **IMPLEMENTS** this contract.
* The **`app/`** directory (your executable) **CONSUMES** this contract.

-----

### An Analogy: The Restaurant

* **`src/` (The Library) = The Kitchen**

    * This is where all the complex, messy work gets done (implementation).
    * The kitchen has its own internal processes, its own tools, and maybe even its own private notes (`private_header.h`) that the customer should *never* see.

* **`include/` (The Public API) = The Menu**

    * This is the clean, simple, public-facing "contract" the kitchen offers to the customer.
    * It lists *what* you can get (`dict_create()`, `itos_convert()`) but says *nothing* about *how* the chef actually makes the dish (the implementation in `dict.c`).

* **`app/` (The Executable) = The Customer**

    * The customer (`app/bigram.c`) only looks at the Menu (`include/bigram/dict.h`) to decide what to order.
    * The customer should *never* be allowed to walk into the kitchen. They just trust that `dict_create()` will work as advertised on the menu.

### Why This is So Important

1.  **Encapsulation:** Your `app` doesn't need to know (and *shouldn't* know) the internal workings of your library. By only including `"bigram/dict.h"`, it is decoupled from the implementation in `src/dict.c`. You could completely rewrite `src/dict.c` (e.g., to use a different hashing algorithm), and as long as the "contract" in `dict.h` doesn't change, your `app` **will re-compile and work perfectly** without a single change.

2.  **Clarity:** When you look in `include/`, you are seeing the public API of your library. When you look in `src/`, you are seeing the implementation. This separation makes the project infinitely easier to navigate.

### What About Private Headers?

This leads to the next logical question: "What if my library `src/` files need to share a header that the `app/` should *not* see?"

This is a common case\! Imagine you have an internal helper function or struct defined in `src/internal_utils.h` that `src/dict.c` and `src/itos.c` both need, but it's *not* for public use.

In this case, you **do not** put it in `include/`. You keep it inside `src/`:

```
bigram-model/
├── include/
│   └── bigram/
│       ├── dict.h   # <-- Public API
│       └── itos.h   # <-- Public API
└── src/
    ├── CMakeLists.txt
    ├── dict.c       # <-- Implements dict.h, can include internal_utils.h
    ├── itos.c       # <-- Implements itos.h, can include internal_utils.h
    └── internal_utils.h # <-- PRIVATE header, for 'src' only
```

In your `src/CMakeLists.txt`, you would tell CMake that `src/` is *also* an include directory, but only for the `bigram_lib` target itself.

You would change `src/CMakeLists.txt` to:

```cmake
# ...
add_library(bigram_lib ...)

target_include_directories(bigram_lib
    # PUBLIC: What consumers (like 'app') get
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include 

    # PRIVATE: What only the library itself ('src') gets
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src
)
```

Now, `src/dict.c` can do `#include "internal_utils.h"`, but your `app/bigram.c` cannot. If it tries, the compiler will fail (which is exactly what you want).

### Summary Table

| Directory | Purpose | Analogy | Who Uses It? |
| :--- | :--- | :--- | :--- |
| **`include/`** | **Public API** (The Contract) | The Menu | `app/` (Consumer) & `src/` (Implementer) |
| **`src/`** | **Implementation** (The Details) | The Kitchen | `src/` only |
| **`app/`** | **Consumption** (The Use Case) | The Customer | `app/` only |

So, you were right to question it\! The `include/` directory isn't a "shared folder" in the messy sense. It's the **clean, formal interface** that the `src` library *provides* for the `app` executable to *consume*.

Would you like to explore that `PUBLIC` vs. `PRIVATE` setting in `target_include_directories` a bit more? It's a fundamental concept in Modern CMake.