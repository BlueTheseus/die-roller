Note: This project is currently under development, and only basic functionality
is implemented at the moment.

# die-roller
This is a small terminal program for rolling digital dice.

# Use
```
die-roller [OPTIONS]... [NUM_DICE]d[NUM_SIDES]...
```

You can provide the dice to roll using a few simple methods:
- A 20-sided die will be rolled when not given any arguments.
- An argument of `NdS` will roll `N` dice with `S` sides.
- A lone number will roll one die with that many sides.
- Via stdin (e.g. `echo 'd6' | die-roller` or `cat die_rolls.txt | die-roller`).

Note that both the number of dice and the number of sides on each die must be
positive integers.

# Options
- `--std-lib`: Use the random functions provided by the standard library as source of randomness to determine rolls.
- `--dev-urandom`: Use `/dev/urandom` as source of randomness to determine rolls.
- `--dev-random` : Use `/dev/random` as source fo randomness to determine rolls.
- `--label`: Print die lables (e.g. `2d20: 16, 5`).
- `--table`: Print die rolls in a table.
- `--help`
- `--version`


# Build
This project uses `make`:
- `make`: Build executable
- `make clean`: Restore source directory to clean state by deleting extra files.
