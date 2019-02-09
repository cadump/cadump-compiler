# Cadump Language

## Main principles

- every object has stdin, stdout
- every object has child stderr object, except for stderr object
- its parent's responsibility to handle errors
- everything is an object, either nested or not
- every object has array of its children accesible by their name or index
- every object is ambiguous
- unspecified left side of stdin/stdout in an object defaults to parent's stdin/stdout
- all, even nested objects are accessible by their parents
- objects are destroyed once made `nil`
- objects are truly pure => they can only acces their own child objects or arguments
- program ends by number (exit code)

---

## Enviromental objects

### std

object representing input and output stream of the program

Params: `[array of objects]`
Evals: `[stdin]`

### if

object providing basic conditions (if, else)

Params: `[evaluation]`,`if true`,`else (optional)`
Evals: `[evals  the second or third object]

## Syntax

### pipelines

- `>` use stdout of the right object as stdin of the left object
- `<` use stdout of the left object as stdin of the right object
- `>>` append left object to the array of right object's children
- `<<` append right object to the array of left object's children

### objects

objects are defined by `name` or by brackets `()` or by index in parent object

### children

objects can acces children of a child by `.` followed by name of the child

### stdin

objects can get their parameters with `>` with empty left side

### stdout

objects can evaluate with `<` with empty left side

### stderr

objects can access stderr by `^` after their name

### evaluation

objects can be evaluated by:
- `?`  returns object's value (dereference)
---
- `?=` left object is equal to right object
- `?>` left object is greater than right object
- `?<` left object is smaller than right object
- `?>=`left object is greater or equal to right object
- `?<=`left object is smaller or equal to right object
returns `true` if true, `false` if false, `nil` if can't be evaluated

### exit codes

