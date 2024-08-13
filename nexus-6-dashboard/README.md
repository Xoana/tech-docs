# Nexus-6 2.0 Dashboard Processing

This repository provides the functionality necessary to generate and publish the Nexus-6 2.0 live dashboards, as well as generate individual Nexus-6 dashboard files (.twbx files) for partner runs.

**Topics**
* [Overview](#overview)
    * [Important Changes in Nexus-6 3.0](#important-changes-in-productx-30)
    * [Knowledge Requirements](#knowledge-requirements)
    * [Workspace Requirements](#workspace-requirements)
    * [Dashboard Components](#dashboard-components)
* [Before You Begin](#before-you-begin)
* [Nexus-6 Development Process](#productx-development-process)
* [Nexus-6 Release Process](#productx-release-process)
    * [Release Preparation](#release-preparation)
    * [Deployment Procedure](#deployment-procedure)
* [Additional Topics](#additional-topics)

## Overview

Nexus-6 provides the following dashboards:
* **Nexus-6**: The Nexus-6 dashboard provides insights into customer and partner networks; for details, refer to [Nexus-6 Dashboard](./docs/productx_dashboard.md).
* **Nexus-6 Compare**: The Nexus-6 Compare dashboard allows users to compare data points across multiple runs for the same customer; for more information, refer to [Nexus-6 Compare Dashboard](./docs/productx_compare.md).

The Nexus-6 dashboards are built using Tableau Desktop and published to the Tableau production server using live connections to Snowflake views. 

### Important Changes in Nexus-6 3.0

Nexus-6 3.0 introduces a single-access dashboard that combines the classic Nexus-6, ProductY, and ProductZ dashboards.

**Note**: Partner requests are currently unsupported in Nexus-6 3.0.

### Knowledge Requirements

* [Nexus-6 Development Process](#productx-development-process)
* Nexus-6 Snowflake Development Guide
* [Git](https://www.atlassian.com/git/tutorials/learn-git-with-bitbucket-cloud) & [Gitflow](https://www.atlassian.com/git/tutorials/comparing-workflows/gitflow-workflow)
* [Python](https://www.python.org/)
* [Tableau Desktop](https://www.tableau.com/products/desktop)
    
### Workspace Requirements

**Note**: All workspace requirements are local unless otherwise specified.

* productx_dashboard (git repo)
* Snowflake Cloud Gateway Account (External Workspace)
    
    For information about how to set up your cloud gateway environment, refer to the Nexus-6 Snowflake Development Guide (Box document).

* [Tableau Desktop](https://www.tableau.com/support/releases)

* [Python](https://www.python.org/downloads/)
* productx-dashboard-venv (Python Virtual Environment)

    For information about how to create the *productx-dashboard-venv* virtual environmnet, refer to [Create a Python Virtual Environment](./docs/create-venv.md).


### Dashboard Components

The source code for this repo is contained in the src folder; the src folder includes the following subfolders:

| Folder | Contents  |
| :------------- |:-------------|
|config | Configuration files. |
|dependencies| Code shared across multiple scripts. |
|docs| Additional documentation. |
|jobs| Automation scripts run on Ctrl-M jobs. |
|publish| Script to publish the live dashboards. |
|templates| Tableau template (twbx) files. |
|tools| Additional scripts used in installation and development. |

## Before You Begin

Before contributing to this codebase, ensure you have completed the following steps:

1. Ensure you have knowledge of the items listed in [Knowledge Requirements](#knowledge-requirements) section.
1. Ensure you have read and understand the [Nexus-6 Development Process](#productx-development-process).
1. Install the necessary applications as described in [Workspace Requirements](#workspace-requirements).
1. Clone this repository to your local machine.

## Nexus-6 Development Process

This procedure describes the steps necessary to make changes to this codebase.

**Note**: This procedure assumes you have already cloned this repository.

For each change you want to make to this codebase, complete the following steps:

1. Create a Jira that describes the changes you want to make.
1. Within this repository on your local machine, check out the develop branch and pull the latest:
    ```
    $ git checkout develop
    $ git pull origin
    ```
1. Using Gitflow, create a feature branch using the following naming convention: 

    ```{jira_number}-{description_of_change_with_no_spaces}```

    For example:

    ```
    $ git flow feature start NEXUS6-1234-update-template
    ```

1. Make your changes. 
    
    **<span style="color:red">IMPORTANT!</span>** Refer to the following topics before making any changes to the templates:

    * [Nexus-6 Dashboard](./docs/productx_dashboard.md)
    * [Nexus-6 Compare Dashboard](./docs/productx_compare.md)

1. Verify your changes; to verify your changes, complete the following steps:

   1. Publish the template(s) to the *Dev* project on the Tableau production server.  
            
        For information about publishing dashboards, refer to [Publishing Templates](./docs/publish_templates.md).

    1. View the template(s) within the *Dev* project on the production server to confirm template changes.

1. Once you have verified your changes, stage the files in your local repo:

    To stage one file:
    ```
    $ git add <file_name>
    ```
    To stage all files:
    ```
    $ git add .
    ```
1. Commit the staged files to your local branch:

    ```
    $ git commit -m "Add your message here"
    ```

1. Push the committed files to your remote branch:

    ```
    $ git push origin
    ```
1. Submit a pull request:
    1. Go to the branch on github.com, and click **Compare and Create Pull Request**.
    1. Enter a title; for example, you can use the name of the branch.
    1. In the text area, add a link to the Jira so that reviewers can easily access the Jira notes.
    1. Click **Create Pull Request**.
    1. In the top-right corner, assign reviewers to the PR.

Once the PR is approved, the feature branch will be merged to develop by a member of the development team.

## Nexus-6 Release Process

These procedures describe how to release the Nexus-6 dashboard code.

**Note**: These procedures are to be completed by the development team only.

### Release Preparation
1. Use gitflow to start and finish a release branch (specifying the appropriate release number as the tag).
1. Push changes to develop and master branches.
1. Add release notes to the GitHub tag.

### Deployment Procedure

Complete the following steps to deploy Nexus-6 dashboard changes:

1. On the cgwproductx cloud gateway account, pull the latest from the productx-dashboard repo:
    1. Log into the cgwproductx account.
    1. Change to the productx-dashboard repo under the appropriate folder:
        * For the UAT release, change to **uat_productx > productx-dashboard**.
        * For the production release, change to **PROD > productx-dashboard**.
    1. Run `git status` to ensure the master branch is checked out and that no conflicting changes are on the server.
    
        **Note**: If the branch is not set to master, run `git checkout master`; if conflicting files are on the server, run `git reset --hard` to reset the local master branch.

    1. Run `git pull origin` to pull the latest from the master branch.
    1. Run `git describe` and verify the release version (tag).
1. On your local machine, publish template changes to the Tableau server:
    1. Activate the `productx-dashboard-venv` python virtual environment.
        
        **Note**: For information on how to create the productx-dashboard-venv virtual environment, refer to [Create a Python Virtual Environment](./docs/create-venv.md).

    1. Locally check out the master branch, and change to the **./publish** folder.
    1. Run the ```publish_templates.py``` script for each template that needs to be published:

        * For the UAT release, run the following command: 
        
            `python publish_templates.py --template-to-publish {template_name.twbx} --env stage --table-prefix UAT_`
        
        * For the production release, run the following command: 
        
            `python publish_templates.py --template-to-publish {template_name.twbx} --env production`
        
        For more information about running the publishing script, refer to [Publishing Templates](./docs/publish_templates.md).


## Additional Topics
* [Nexus-6 Automation](./docs/productx_automation.md)
* [Nexus-6 Compare Dashboard](./docs/productx_compare.md)
* [Nexus-6 Dashboard](./docs/productx_dashboard.md)
* [Frequently Asked Questions](./docs/frequently-asked-questions.md)
* [Publishing Templates](./docs/publish_templates.md)
* [Troubleshooting](./docs/troubleshooting.md)