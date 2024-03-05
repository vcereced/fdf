<p align="center">
  <a>
    <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/8/8d/42_Logo.svg/1200px-42_Logo.svg.png" alt="Logo" width="200" height="200">
  </a>

  <p align="center">
    Because simple graphics is not enougth<br>
    Project fdf of 42 school
    <br />
	</p>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Makefile-8A2BE2">
  <img src="https://img.shields.io/badge/C-4682B4">
  <img src="https://img.shields.io/badge/Shell-2E8B57">
  <img src="https://img.shields.io/badge/Gcc-00FF00">
  <img src="https://img.shields.io/badge/AppKit-2E8B57">
  
</p>

## &#x1F4CC; Index 
- [📌 Index](#-index)
- [✨ What is FdF?](#-what-is-fdf)
- [🕹 Controles](#-controles)
- [💻 Usage](#-usage)
- [📖 Examples](#-examples)

## &#x2728; What is FdF?

FdF is a project in which we convert a file with a grid of height values into a 3d wireframe using a simple graphics.
			
## 🕹 Controles

|Input|Action|
|---|---|
|`Mouse (Right Clicked)`| X/Y axis Rotation|
|`Mouse (Left Clicked)`| Traslation|
|`Mouse Scroll`| Zomm In/Out|
|`Arrows`| X/Y axis Rotation. Cmd cliked +90ª|
|`Q / W`| Z axis Rotation. Cmd cliked +90ª|
|`+ / -`| Z axis divisor|
|`L`| Lines ON /OFF|
|`D`| Dots ON /OFF|
|`X`| Extra Wired ON /OFF|
|`G`| GEO view ON /OFF|
|`H`| On GEO view Shadow side ON /OFF|
|`I`| ISOMETRIC view |
|`P`| PARALEL view |
|`S`| Make the magic happends |
|`B / Cmd+B`| Blendig + / -|
|`1`| Terrain Color Scheme|
|`2`| White & Black Color Scheme|
|`3`| Black & White Color Scheme|
|`4`| Earth Color Scheme|
|`ESC ❌`|Cierra la ventana|

## &#x1F4BB; Usage

`make` to compile.

`bonus` to compile with bonus features.

`make clean` remove .o files.

`make fclean` remove .o files and .a files and executable.

## &#x1F4D6; Examples

Let's create a ``example.fdf`` file with a grid of heights of the map.

```
0 0 1 2 3 4 5 6 7 8 9
0 0 0 1 2 3 4 5 6 7 8
0 0 0 0 1 2 3 4 5 6 7
0 0 0 0 0 1 2 3 4 5 6
0 0 0 0 0 0 1 2 3 4 5
0 0 0 0 0 0 0 1 2 3 4
0 0 0 0 0 0 0 0 1 2 3
0 0 0 0 0 0 0 0 0 1 2
0 0 0 0 0 0 0 0 0 0 1
```
Execute this command in the terminal.

```bash
make  && ./fdf ./example.fdf 
```
Output should be:
```
IMAGEN!!!!!!!!!!
```
With bonus features.
```bash
make bonus  && ./fdf ./42.fdf 
```
Output should be:
```
IMAGEN!!!!!!!!!!
```


