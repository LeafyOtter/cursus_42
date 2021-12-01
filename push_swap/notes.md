# Algorithm sort

## Pre-sort

1. Index stack
	Relatively straight forward
2. Markup which elem to push
	Two methods : greater than and by index

## From a to b

```
WHILE stack A has elements with "false" value in "Keep in Stack A" field
      IF sa (swap a) is needed
            perform sa (swap a) command
            update markup
      ELSE IF head element of stack A has "false" value in "Keep in Stack A" field
            perform pb (push b) command
      ELSE
            perform ra (rotate a) command
```

perform sa if more elem will be kept. do two markup, one before and after,  
keep the highest.

## From b to a

```
WHILE stack B is not empty
      choose element in stack B for moving to stack A
      move stack A and stack B to prepare them for pa (push a) with chosen element
      perform pa (push a) command
```
how to choose?
	calculate which elem require the lowest number of move

## Align a
rotate till smallest element is first

[Reference for this algorithm](https://github.com/VBrazhnik/Push_swap/wiki/Algorithm)

## Todo

- [ ] Check why it doesn't work for some combination
- [ ] Implement greater than markup
- [ ] Don't write instructions as soon as it's written,  let's stock them
so we can count them and pick the best method
- [ ] Optimization basicly

