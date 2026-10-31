Versioning is based on `[STABLE].[FEATURE].[BUG FIX]`

# Bugs
N/A

# To Do
- Implement error-handling for all functions which provide it.
- Accept arguments from `stdin`.
- Option-handling
    - label
    - table
        - Option to state how many columns wide to print the result table.
    - std-lib
    - /dev/urandom
    - /dev/random
    - Option to run multithreaded calculations (for many, many die rolls). This
      might be achieved by storing results in a large array and letting each
      thread compute rolls for a certain (yet variable) amount of dice. I want to
      allow variable amount of threads used too.
- Show an animation while rolling.
    - Option to vary the rate at which numbers are incremented.
    - "Spin the Wheel" option to press a key telling the die when to stop rolling.
    - Physics simulation of rolling a die on a table with a random starting velocity.
        - Roll bullet dice via physics simulation by default with option to disable.
- Roll irregular dice like a bullet die.
    - irregular dice must be provided custom chance tables to operate with
- Make manpage.
- Add ability to randomly choose x items from a provided list of items with or without replacement

