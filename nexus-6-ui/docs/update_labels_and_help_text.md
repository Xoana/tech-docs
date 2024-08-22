# Update Column Labels and Help Text

This procedure describes how to update column labels and help text in the ProjectX UI.

## Before You Begin

Before you begin, review the following topics in the productx-ui repository:
* [Development Process](./productx-development-process.md)
* [Workspace Requirements](../README.md#workspace-requirements)
* [Install and Run the UI Locally](./install_and_run_the_ui_locally.md)

## Procedure

Complete these steps to update labels and help text in the Nexus-6 UI:

1. On your local machine, open a terminal in your local productx-ui git repository.
1. Run the following commands to check out and pull the latest from the develop branch: 

    ```
    $ git checkout develop
    $ git pull origin
    ```
1. Run the following command to create a feature branch: 

    ```
    $ git flow feature start <branch_name>
    ```
    
    Where `branch_name` is the name of the branch to create.
1. In an IDE (recommended) or text editor, open the config.ts file located in the following application folder: `src\app\shared`

1. Locate the configuration object for the column you want to change. 
    
    The column configurations are defined in the columnConfig object and appear as follows: 

    ```
    customerNameConfig: {
        required: true, 
        apiColumnName: "customerName",
        fieldLabel: "Customer Name",
        tooltipText: "Name of the customer.",
        validationText: `${validationConfig.required.message}`,
        validator: `${validationConfig.required.pattern}`,
        type: CellType.Text,
        apiType: ApiType.String,
        defaultWidth: 225 
    },
    ```

1. To update the column label, modify the `fieldLabel` value.
1. To update the help text, modify the `tooltipText` value.
1. Once your changes are complete, verify locally:

    1. Open a terminal in the application folder.
    1. Run the following command:
        ```
        $ ng serve
        ```
    1. Access the UI on your local machine at http://localhost:4200.
    1. Verify that your changes appear as expected.

1. Once you have confirmed your changes, commit the file and push to the remote branch:

    1. Run the following command to stage your file(s): 
    
        ```
        $ git add .
        ```
    1. Run the following command to commit the file(s): 
    
        ```
        $ git commit -m 'Description of changes'
        ```
    1. Push the files to the remote branch: 
    
        ```
        $ git push origin
        ```

1. Submit a PR:

    1. Access your branch on the GitHub website.
    1. Click the **Contribute** button, and then click the **Open pull request** button.
    1. In the Add a title field, enter a title.
    1. In the Add a description text box, add a link to the Jira and a description of the change.
    1. Click the gear icon next to Reviewers to add reviewers.
    1. Click the **Create pull request** button to create the pull request.

    
    Once your pull request is approved, it will be merged to the develop branch by a member of the development team.

<hr/>

[Return to README](../README.md)