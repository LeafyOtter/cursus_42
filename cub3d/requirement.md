# requirements

## to_do

- bonus : try to add door. (wont do it)
- if i have time animated stripe i guess. (same)
- ~~rewrite load_texture()~~
- ~~fix issue with texture when getting near it~~
- ~~implement color management for ceiling floor~~
- ~~implement error gestion if invalid texture~~
- ~~quit cleanly~~
- ~~norm the shit of everything~~
- ~~add a define/sth to change keybinds easily (not needed honestly) (done anyway lol)~~
- ~~ bonus : so a nicer looking minimap, mouse integration.~~

## subject

- use minilibx
- managment of window smooth, changing window, minimizing, etc
- display different wall textures that vary with orientation
- ceiling and floor different colors
- left and right arrow keys look left and left
- w a s d to move
- esc close window and quit **cleanly**
- clicking on red cross must close
- use of mlx image

## parsing (still subject

- only 6 characters 01NSEW
- map closed by walls if ! error
- element can be separated by \n
- element can be in any order (except map)
- element can be separated by one or more space(s) (so whitespaces?)
- must be able to parse any kinds of map (do i take care of tab?)
- identifiers, NO, SO, WE, EA, F, C
- any kind of error must return Error\n and exit properly

## bonus

- wall colisions (already implemented)
- minimap system (should be easy)
- door (no)
- animated sprite (honestly no)
- rotate the point of view with the mouse (should be easy)
