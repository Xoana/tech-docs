# How to Create Sphinx Documentation

_Add create a virtual environment_

## Step 1: Install Sphinx
Make sure you have Sphinx installed. Run:

```bash
pip install sphinx
```

## Step 2: Create a docs Directory
Navigate to your project directory and create a docs folder:

```bash
mkdir docs
cd docs
```
## Step 3: Initialize Sphinx
Run the following command inside the docs directory:

```bash
sphinx-quickstart
```
This will prompt you for various settings. Here are some recommended inputs:

```bash
Separate source and build directories: Yes
Project name: Sample Project
Author name: Your name
Project version: 1.0 
Language: Leave empty for English.
Sphinx will generate a set of files, including conf.py and index.rst.
```

## Step 4: Configure Sphinx
Open the conf.py file and make the following adjustments:

Add the sample_project directory to sys.path:

```python
import os
import sys
sys.path.insert(0, os.path.abspath('../..'))
```
Enable the autodoc extension: Uncomment or add:

```python
extensions = ['sphinx.ext.autodoc']
```

## Step 5: Create the Documentation Structure
Edit index.rst to include your modules:

```
Welcome to Sample Project's documentation!
==========================================

.. toctree::
   :maxdepth: 2
   :caption: Contents:

modules
```

Use the sphinx-apidoc tool to generate .rst files for your modules: From the docs directory, run:

```bash
sphinx-apidoc -o . ../sample_project
```
## Step 6: Build the Documentation
Run the following command in the docs directory to build the HTML documentation:

```bash
make html
```
Your HTML documentation will be located in the _build/html folder. Open the index.html file in your browser to view it.
