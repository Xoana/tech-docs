# Add a Column to the Requests Table

This procedures describes how to add a column to the requests table.

## Before You Begin

Set up your local development environment as described in [Set Up Your Local Development Environment](../README.md#set-up-your-local-development-environment).

## Procedure
To add a column to the requests table, complete these steps:

1. In the requests.config.ts file, add the column details to the ```columnConfig``` object in the order you want it to appear on the requests table.

    **TIP**: To make edits easier, you can pick an existing column that most closely matches the column you want to add and copy the config object for that column.

    The column config object appears as follows:

    ```
      newColumnConfig: {
        required: false,
        dbColumnName: "newColumn",
        fieldLabel: "New Column Label",
        tooltipText: "New column help text.",
        validationText: validationConfig.min3max256.message,
        validator: `(?=${validationConfig.min3max256.pattern}|${validationConfig.nullable.pattern})`,
        type: CellType.Text,
        apiType: ApiType.String,
        defaultWidth: 225
      },  
    ```

    The object keys are as follows:
    * **required**: Boolean value that indicates whether the column is required on the requests table; set to ```true``` if this column should be required.
    * **dbColumnName**: Name of the API field; this value should be the name of the column as it appears in the API. Also, note, this name should be added as the key value, along with the "Config" text; e.g. ```newColumnConfig```.
    * **fieldLabel**: Name of the column; this value appears as the column heading on the requests table and the form labels on the request forms.
    * **tooltipText**: Text to include in the tooltip; this value appears when the cursor is placed over the info icon on the requests table and in the create request forms.
    * **validationText**: Text to include in the validation message; one or more of the ```ValidationConfig``` message values.
    * **selectOptions**: For drop-down columns only, this value should be set to ```NONE_TYPE```; the ```NONE_TYPE``` value causes the UI to retrieve the drop-down values from the REQUEST_TRACKER_COLUMN_CONFIG table in Snowflake.
    * **validator**: Validator for this column; one or more of the ```ValidationConfig``` pattern values. If the validation pattern you require is not available in the validationConfig object, you will need to add it; for more information, see [Add a Validation Object](#add-a-validation-object).
    * **type**: Column data type on the requests table; refer to the ```CellType``` object for valid values.
    * **apiType**: Column type in the API; refer to the ```ApiType``` object for valid values.
    * **defaultWidth**: Default width of the column on the requests table.
1. Make the following additional changes based on user role:
    * If the column should be hidden for read-only users, add the column name to the ```restrictedColumns``` array.
    * If the column should be read-only for all users, add the column name to the ```readOnlyFields``` array.
    * If the column should be read-only for all users except admins, add the column name to the ```readOnlyExceptAdminFields``` array.
    * If the column can be edited by readwrite-restriced role, add the column name to the ```editOnlyReadWriteRestricted``` array.
1. If the column is of type CellType.List (which includes values separated by a comma) and it will appear on one or more request forms, add the column name to the ```listFields``` array. The ```listFields``` array is used to ensure the list values are in the appropriate format for submitting a request to the UI.
1. Verify your changes by running the UI locally; for more information, see [Run the UI Locally](./install_and_run_the_ui_locally.md#run-the-ui-locally).

    **Note**: If the DB and API changes are not deployed to the DEV environment, you will receive an error if you attempt to update the field.

1. Once you have verified your changes, complete the development process by committing your changes and submitting a PR; for more information, see [Nexus-6 Development Process](../README.md#productx-development-process).

## Add a Validation Object

A validation object appears similar to the following:
```
min3max256: {
    pattern: '^[\\s\\S]{3,256}$',
    message: 'The value must be between 3 and 256 characters.' },
```
Where:
* **pattern** is the regex pattern to use for the validation. This regex pattern should be the same pattern used in the API.
* **message** is the message that will appear on the UI if the validation fails.

To add a validation object, complete these steps:
1. Add the validation object to the ```validationConfig``` object in the [requests.config.ts](../src/app/shared/requests.config.ts) file.
1. Reference the validation object in the ```validationText``` and ```validator``` keys in the ```columnConfig``` object for the appropriate column.

<hr/>

[Return to README](../README.md)