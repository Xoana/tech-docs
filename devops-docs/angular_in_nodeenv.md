# How to create an Angular project in nodeenv

This procedure describes how to create a nodeenv virtual environment on Windows for developing Angular applications.

**Note**: This procedure uses Git Bash for Windows; therefore, Linux-based commands will be used throughout the procedure.

## Prerequisites

* Python
* Git Bash or Windows Command Prompt
    
    **Note**: This procedure uses Git Bash for Windows.

* Knowledge of Linux-based commands or equivalent commands for Windows operating system.

## Before You Begin

Before you begin, determine which versions of Angular to use with your Node.js version

**Note**: Node.js and Angular versions must be compatible; to determine which versions of Angular to use with your Node.js version, refer to [Version compatibility](https://angular.io/guide/versions).

## Procedure

1. Create a node virtual environment for the Node.js version you want to use; for information about creating a node virtual environment, refer to [How to create a node virtual environment](./create-nodeenv.md).

1. Change out of your _virtual-environments_ directory, and create a projects directory:

    ```
    (venv) $ mkdir projects
    ```

1. Change into the _projects_ directory, and run the following command to create an Angular application:

    ```
    (venv) $ npx @angular/cli@<version> new <project_name>
    ```

    Where `<version>` is the version of Angular to install and `<project_name>` is the name of the Angular project to create.

1. Change into the application directory, and run the following command to build and serve the application:

    ```
    (venv) $ ng serve
    ```

1. Access the application in a browser at `http://localhost:4200/`.
