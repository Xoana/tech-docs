# Publishing Templates

The `publish_templates.py` script is used to publishing templates to the Tableau production server; this script supports the following templates to the Tableau production server:

* productx_3.0_template.twbx
* productx_compare_template.twbx
* productx_snowflake_costs_template.twbx

In addition, the script provides the following flags to validate items in the Nexus-6 3.0 template (`productx_3.0_template.twbx`):

* `--validate-template`: Flag that instructs the script to call the `--validate-template.py` script, which parses the XML to verify items, such as default filter settings.
* `--validate-warranty-types`: Flag that is passed to the `--validate-template.py` script to verify WARRANTY_TYPE column values; this option queries the database to retrieve current column values. This option requires the `--validate-template` flag.

**NOTE**: These options are supported only for the `productx_3.0_template.twbx` file.

## Before You Begin

1. Generate a Tableau access token if you do not already have one; for more information, refer to [Creating personal access token](https://help.tableau.com/current/pro/desktop/en-us/useracct.htm#create-and-revoke-personal-access-tokens).

1. Create the tableau_credentials.yaml file and save it to the *productx-dashboard > src > publish* folder in this repository.
    
    This file contains the credentials used for publishing the templates to the Tableau server; the format is as follows:
    ```
    token_name: <your_token_name>
    token_secret: <your_token_secret>
    sf_user: productx_rpt_svc
    sf_pass: <password>
    ```
    **Notes**:
    * The *tableau_credentials.yaml* file is currently ignored by git and should not be committed to the repo.
    * If you are republishing the dashboards to change the password, update the `sf_pass` value in this file.

1. If it is not already created, create the *productx-dashboard-venv* python virtual environment; for more information, refer to [Create a Python Virtual Environment](./docs/create-venv.md).

### Usage

The commands to publish the templates to the Tableau production server are as follows:

* DEV: ```python publish_templates.py --template-name {template_name.twbx} --env dev --table-prefix DEV_```
* UAT: ```python publish_templates.py --template-name {template_name.twbx} --env stage --table-prefix UAT_```
* Production: ```python publish_templates.py --template-name {template_name.twbx} --env production --table-prefix ''```

To run the Nexus-6 3.0 template validator script, use this command (for example):

```python publish_templates.py --template-name {template_name.twbx} --env dev --table-prefix DEV_ --validate-template [--validate-values]```

**Note**: If `--template-name` is not provided, you will be prompted to select a template or exit the script:

```
1: productx_3.0_template.twbx
2: productx_compare_template.twbx
3: productx_snowflake_costs_template.twbx
4: All
5: Exit
```

Refer to [CLI Options](#cli-options) for a complete list of command-line options.

### CLI Options
* ```--template-name```: Name of the template to publish; if notspecified, user is prompted to select a template.
* ```--env```: Environment in which to publish the dashboards; one of the following: dev, stage, production.
[default: dev]
* ```--table-prefix```: Prefix of the Snowflake table.  [default: DEV_]
* ```--publish-config```: Path and file name of the Tableau config file. 
* ```--validate-template```: Flag used to instruct the script to validate the Nexus-6 3.0 template before publishing. This flag is supported only for the productx_3.0_template.twbx template.
* ```--validate-values```: Flag used to validate WARRANTY_TYPE values, which requires a call to Snowflake. This option is used with the --validate-template flag.
* ```--skip-publish```: Flag used to skip publishing the dashboard to the Tableau production server.
* ```--skip-delete```: Flag used to skip creating the workbooks.
* ```--help```: Show this message and exit.