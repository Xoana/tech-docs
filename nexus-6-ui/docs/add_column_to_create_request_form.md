# Add a Column to the Create Request Forms

This procedures describes how to add a column to the create request forms.

## Before You Begin

1. Set up your local development environment as described in [Set Up Your Local Development Environment](../README.md#set-up-your-local-development-environment).
1. Review the following topic [About Request Forms](./about-request-forms.md).

## Procedure

To add a column to one or more request forms, complete these steps:

1. In the create-request.config.ts file: 
    1. Add the column name to ```RequestRecord``` (in alphabetical order).

        **Note**: All data types should be string.

    1. If the column requires validation, add form validators to ```fieldValidators```.

        **Note**: These validators are different than the requests table validators and are used only in the request forms.

1. In the create-request.component.ts file:
    1. Add a ```FormControl``` to the ```FormGroup``` and reference the values you added to ```RequestRecord``` and ```fieldValidators```.
    1. If the field is required on one form but is not required on another form, add the proper validations to the ```submitCreateAction``` function. For example, see ```applianceId``` under ```case productSingle```; the appliance ID is required only on the product form.

1. Add the column to the create-request.component.html file.

    **Note**: The create request forms use Nexus-6 UI Angular components instead of plain HTML; for more information regarding the Cisco UI Angular components, refer to the productx-ng repository.

    To add a column to the html file, complete these steps:

    1. Locate the area in the file where the field should be added.

    1. Prepare the form field code:
        1. Create the ```<cng-form-field>...</cng-form-field>``` element for the column you want to add.
        
            **Tip**: To facilitate adding the new column, you can copy the ```<cng-form-field>...</cng-form-field>``` element of an existing column that most closely matches the data type and field value of the column you are adding.

        1. If you copied the ```<cng-form-field>``` element from an existing column, ensure you search for the copied field name and replace it with the new field name.
        1. Add validations to ```span.alert_message``` accordingly.
        1. If the field should be added to or excluded from one of the forms, add the ```*ngIf``` directive based on which forms should include the column.

1. Verify your changes by running the UI locally; for more information, see [Run the UI Locally](./install_and_run_the_ui_locally.md#run-the-ui-locally).

    **Note**: If the DB and API changes are not deployed to the DEV environment, you will receive an error if you attempt to submit a request with a value populated in the new field.

1. Once you have verified your changes, complete the development process by committing your changes and submitting a PR; for more information, see [Nexus-6 Development Process](../README.md#productx-development-process).

<hr/>

[Return to README](../README.md)