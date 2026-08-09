# Quasimodo
Automate static websites with daily content organized by calendar date.

## About this program

> _You know, Quasimodo predicted all this._

Quasimodo is a simple program written in C++ designed to automate the creation of a yearly calendar website where each day displays unique content, like quotes, facts, reminders, etc. Instead of manually writing 365 HTML files, you provide your content once, and Quasimodo generates the entire file structure, organized by year/month/day.

## How to use the program

Download the repository and run the following command in your terminal:

```
g++ -o quasimodo main.cc
```

Next up, you'll need a text file with:

- The year which the daily contents are for.
- The 365 (or 366 if it is a leap year) daily contents.

For example, in a file called `file.txt`:

```
2026
Happy New Year!
Stay hydrated and smile today.
[...]
365 days complete! Congratulations!
```

To run the program, use the following command:

```
./quasimodo < file.txt
```

The final structure should be something like this:

```
2026
├── 1
│   ├── 1.html
│   ├── 2.html
│   ├── 3.html
│  (...)
│   └── 31.html
├── 2
│   ├── 1.html
│  (...)
│   └── 28.html
(...)
├── 12
│   ├── 1.html
│  (...)
│   └── 31.html
today.html
```

This repository also includes a `today.html` file containing JavaScript that automatically redirects visitors to the current day's content.

A demo file is also given for basic testing, called `demo.txt`.

## To-do

Here's a list of features pending to be added to Quasimodo:

- [ ] Proper argument handling (i.e. `-i quotes.txt`)
- [ ] Custom HTML template import.

## Program License

This program is released under the MIT license.

The software is provided "as is", without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose and noninfringement. In no event shall the authors or copyright holders be liable for any claim, damages or other liability, whether in an action of contract, tort or otherwise, arising from, out of or in connection with the software or the use or other dealings in the software. 
