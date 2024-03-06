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
- [What is FdF?](#-what-is-fdf)
- [Controles](#-controles)
- [Usage](#-usage)
- [Examples](#-examples)

## &#x2728; What is FdF?

FdF is a project in which we convert a file with a grid of height values into a 3d wireframe using a simple graphics.
			
## 🕹 Controles

|Input|Action|
|---|---|
|`UP`| Increasing heights|
|`DONW`|  Decreasing heights|
|`4 / 8 / 6 / 2`| X axis Y axis movements|
|`/`| Increasing zoom |
|`*`| Decreasing zoom |
|`+`| Increasing scale|
|`-`| Decreasing scale|
|`2`| change isometric mode |
|`3`| change isometric mode|
|`ESC`|Cierra la ventana|

## &#x1F4BB; Usage

`make` to compile.

`bonus` to compile with bonus features.

`make clean` remove .o files.

`make fclean` remove .o files and .a files and executable.

## &#x1F4D6; Examples

Let's create a ``example.fdf`` file with a grid of heights of the map.

```
15 12 10 9  5  4  0  0  0  0
12 10 9  5  4  0  0  0  0  0
10 9  5  4  0  0  2  0  0  0
9  5  4  0  0  2  5  2  0  0
5  4  0  0  2  5  8  5  2  0
5  4  0  0  0  2  5  2  0  0
9  5  4  0  0  0  2  0  0  0
10 9  5  4  0  0  0  0  0  0
10 10 9  5  4  0  0  0  0  0
15 12 10 9  5  4  0  0  0  0
```
Execute this command in the terminal.

```bash
make  && ./fdf ./example.fdf 
```
Output should be:

<img width="521" alt="Screen Shot 2024-03-06 at 12 35 29 PM" src="https://github.com/vcereced/fdf/assets/120835200/355e7150-8a12-4849-983e-38bcc1bdc5ea">

With bonus features.
```bash
make bonus  && ./fdf ./test_maps/42.fdf 
```
Output should be:

![FdF_1](https://github.com/vcereced/fdf/assets/120835200/8e46d15f-7f97-40f8-9223-c4887e26b246)








