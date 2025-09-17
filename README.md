# die-roller
This is a small terminal program for rolling digital dice.

# Usage
```
die-roller [OPTIONS]... [NUM_DICE]d[NUM_SIDES]...
```

You can provide the dice to roll using a few simple methods:
- A 20-sided die will be rolled when not given any arguments.
- An argument of `NdS` will roll `N` dice with `S` sides.
- A lone number will roll one die with that many sides.
- Via stdin (e.g. `echo 'd6' | die-roller`).

Note that both the number of dice and the number of sides on each die must be
positive integers.

# Building
?

# To Do
- Add basic die-rolling functionality.
- Accept arguments via stdin.
- Options to format output. (e.g. `d6: 4`)
    - Option to state how many columns wide to print the result table.
    - Option to run multithreaded calculations (for many, many die rolls). This
      might be achieved by storing results in a large array and letting each
      thread compute rolls for a certain (yet variable) amount of dice.
- Show an animation while rolling.
    - Option to vary the rate at which numbers are incremented.
- "Spin the Wheel" option to press a key telling the die when to stop rolling.
- Roll irregular dice like a bullet die.
- Physics simulation of rolling a die on a table with a random starting velocity.
    - Roll bullet dice via physics simulation by default with option to disable.
