use make to build the project

execute the binary then type "add [type] [name]"

/!\ TYPE CAN ONLY BE : 
- WIRE
- ACTUATOR
- DEVICE

name is whatever you want.

You can use 3 commands :

add [type] [name] -> it will add in the list an element which can be sorted and displayed.

del [ID] -> delete the data stored at [ID] id in the data set.

disp -> displays the data set

sort with 4 flags : TYPE, NAME, ID and -r

sort NAME will sort the database by name
sort TYPE will sort the database by type
sort ID will sort the database by ID
sort [flag] -r will sort in reverse order.

This algorithm is based on the "quick sort" algorithm, and can sort 100K+ elements in a minute or less.
