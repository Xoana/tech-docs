# Nexus-6 Development Process

Before contributing to this project, you must be familiar with our internal development process.

## Before You Begin

Set up your local development environment as described in [Set Up Your Local Development Environment](../README.md#set-up-your-local-development-environment).

## Procedure

Complete the following steps for each change you want to make to this codebase:

1. Create a Jira that describes the change.
1. Within this repository on your local machine, check out the develop branch and pull the latest:
    ```
    $ git checkout develop
    $ git pull origin
    ```
1. Create a feature branch using the following naming convention: 

    ```{jira_number}-{description_of_change_with_no_spaces}```

    For example:

    ```
    $ git flow feature start CRW-1234-update-template
    ```
	
1. Make your changes.

1. Verify your changes:

    1. Open a terminal and change to the `productx-ui` folder.

    1. Run one of the following commands (depending on which version you want to run):
        * Dev: ```ng serve --configuration stage```
        * Stage: ```ng serve --configuration stage```
        * Production: ```ng serve --configuration production```

            **<span style="color:red">IMPORTANT!</span>** When you build the UI using the production configuration, any changes you make in the UI on localhost will be saved to the production tables.            
            
    1. To access the UI locally, open a browser and navigate to http://localhost:4200.

1.	Once you have verified your changes, stage the files in your local repo:

    To stage one file:
    ```
    $ git add <file_name>
    ```
    To stage all files:
    ```
    $ git add .
    ```

1. Commit the staged files to your local repo:

    ```
    $ git commit -m "Add your message here"
    ```
1. Push the committed files to your remote feature branch:

    ```
    $ git push origin
    ```
1. Submit a pull request:
    1. Go to the branch on github.com, and click **Compare and Create Pull Request**.
    1. Enter a title (usually the name of the branch).
    1. In the text area, add a link to the Jira so that reviewers can easily access the Jira notes.
    1. Click **Create Pull Request**.
    1. In the top-right corner, assign reviewers to the PR.

Once the PR is approved, the feature branch will be merged to develop by a member of the development team.

<hr/>

[Return to README](../README.md)