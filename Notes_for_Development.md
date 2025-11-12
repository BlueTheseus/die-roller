Versioning is based on `[STABLE].[FEATURE].[BUG FIX]`

# Bugs
- Crashes with input `1dd20`

# To Do
- Implement error-handling for all functions which provide it.
- Print errors to `stderr`.
    - Be sure to print regular rolls to `stdout`.
- Accept arguments from `stdin`.
- Option-handling
    - help
    - version
    - label
    - table
        - Option to state how many columns wide to print the result table.
    - std-lib
    - /dev/urandom
    - /dev/random
    - Option to run multithreaded calculations (for many, many die rolls). This
      might be achieved by storing results in a large array and letting each
      thread compute rolls for a certain (yet variable) amount of dice. Want to
      allow variable amount of threads used.
    - Show an animation while rolling.
        - Option to vary the rate at which numbers are incremented.
    - "Spin the Wheel" option to press a key telling the die when to stop rolling.
    - Roll irregular dice like a bullet die.
    - Physics simulation of rolling a die on a table with a random starting velocity.
        - Roll bullet dice via physics simulation by default with option to disable.
- Make manpage.

