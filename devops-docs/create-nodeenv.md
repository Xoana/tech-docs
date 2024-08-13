# How to create a node virtual environment

This procedure describes how to create an isolated Node.js virtual environment.


## Prerequisites

* Python
* Git Bash or Windows Command Prompt
    
    **Note**: This procedure uses Git Bash for Windows.

* Knowledge of Linux-based commands or equivalent commands for Windows operating system.

## Procedure

1. Create a directory to store your virtual environment:

    ```
    $ mkdir virtual-environments
    ```

1. Change into the _virtual-environments_ directory, and run the following command to create a python virtual environment:

    ```
    $ python -m venv <venv_name>
    ```

    Where `<venv_name>` is the name of the virtual environment.

1. Run the following command to activate the python virtual environment:

    ```
    $ source <path_to_venv>/Scripts/activate
    ```

1. Run the following command to upgrade pip:

    ```
    (venv) $ python -m pip install --upgrade pip
    ```

1. Run the following command to install nodeenv:

    ```
    (venv) $ pip install nodeenv
    ```

1. Run the following comment to install the latest version of Node.js:

    ```
    (venv) $ nodeenv -p
    ```

    To install a specific version of node, use the `--node` command-line option; for example:

    ```
    (venv) $ nodeenv -p --node=<node_version>
    ```

    Where `node_version` is the version of node.js that you want to install.

    **Note**: If `mklink` is not installed on your machine or you are using a Linux-based terminal (such as Git Bash), you might receive the following error:

    `Error: Failed to create nodejs.exe link`

    Although the error indicates that the installation failed, the environment should work as expected. To view this exception in the nodeenv code, refer to the [nodeenv Github repository](https://github.com/ekalinin/nodeenv/blob/a6585e9a63e1601c4a37f3a1bb8fd0722dd6b51c/nodeenv.py#L983).

1. Run the following command to confirm the node version within your virtual environment: 
    
    ```
    (venv) $ node -v
    ```