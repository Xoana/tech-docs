# Git Procedures

This document describes common git procedures used when contributing to the productx-ui codebase.

**Note**: This document is not intended to be an exhaustive list of git commands or procedures. If you have questions regarding additional commands or procedures, refer to the [GitHub documentation](https://docs.github.com/en/enterprise-server) or search for the topic in Google.

**Topics**
* [Clone the productx-ui Repository](#clone-the-productx-ui-repository)
* [Create a Feature Branch](#create-a-feature-branch)
* [Commit and Push Changes](#commit-and-push-changes)
* [Submit a Pull Request](#submit-a-pull-request)

## Clone the productx-ui Repository

Open a terminal window in the location you want to clone the repository and run the following command:

```
$ git clone https://www-github3.company.com/cxe/productx-ui.git
```

**Note**: If you receive a message instructing you to complete authorization in a browser window, access the browser window, and click the **Authorize** button to complete the cloning process.

## Create a Feature Branch

You must create a feature branch for any change you want to make to this codebase; this feature branch is used to commit your code changes to the repository. 

Before you begin, you must create a Jira that describes the changes you want to make; once the Jira is created, name your branch accordingly.

The naming convention for feature branches is as follows:

```{jira_number}-{brief_description}```

Where *jira_number* is the Jira number and *brief_description* is a brief description of the change.

To create a feature branch, complete these steps:

1. Check out and pull the latest from the develop branch; for information on checking out and pull a branch, see [Check Out and Pull a Branch](#check-out-and-pull-a-branch).
1. While on the develop branch, run the following command to create a feature branch:
    
    ```
    $ git flow feature start <branch_name>
    ```

    For example:
    
    ```$ git flow feature start NEXUS6-1234-add-product-column```

## Check Out and Pull a Branch

To checkout and pull a branch, navigate to the productx-ui repo on your local machine and run the following commands:

```
$ git checkout <branch_name>
$ git pull origin
```

## Commit and Push Changes

To commit and push changes to your remote feature branch, complete these steps:

1. Open a terminal within your local git repo and verify you are on the correct branch:

    ```
    $ git status
    On branch feature/NEXUS6-1234-add-product-column
    ```

    **Important!** Unless applying a hotfix, never push changes directly to the develop or master branches.

1. Stage your file(s):

    * To stage all files, run the following command: 
    
        ```
        $ git add .
        ```

    * To stage one file, run the following command:
        
        ```
        $ git add <file_name>
        ```

1. Run the following command to commit the files:

    ```
    $ git commit -m 'Description of changes'
    ```

1. Run the following command to push the files to your remote feature branch:

    ```
    $ git push origin
    ```

## Submit a Pull Request

1. Go to the [productx-ui](https://www-github3.company.com/cxe/productx-ui) repo in a browser and locate your branch.

1. Click the **Compare and pull request** button.

1. Add a title for the pull request.

1. In the comment box, add a link to the Jira and a description of the change.

1. Assign reviewers by clicking the icon next to *Reviewers* on the right side of the page.

1. Click the **Create pull request** button.

1. Update the Jira with a link to your PR.

Once your pull request is approved, it will be merged to the develop branch by a member of the development team.

<hr/>

[Return to README](../README.md)
