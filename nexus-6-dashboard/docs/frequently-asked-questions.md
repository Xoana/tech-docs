# FAQs & Troubleshooting Notes

## Nexus-6 Dashboard

### What is the first step in troubleshooting any data issues on the dashboard?

If data on the dashboard does not appear as expected, check the filters located on the left side of the dashboard. Some filters exclude values by default.

## Dashboard Development

### Where can I find the Snowflake account credentials that are used for the live connections in the dashboards?

The Nexus-6 dashboards use the ```productx_rpt_svc``` user credentials; you can find the account information on the cgwproductx production environment in the following file: ```~/productx_config/.request-tracker```

### How do I update the account password for the dashboard data sources on the Tableau server?

There are two methods for updating the account password:

**Method 1. Manually update the password on the Tableau Server**

1. Access the workbook on the Tableau server.
1. Click the Data Sources tab.
1. Click **Select All** to select all the data sources.
1. From the Actions menu, select **Edit Connection**.
1. Verify **Embedded password in connection** is checked.
1. In the Change the password field, enter the password.
1. Click **Test Connection** to test the connection.
1. Click **Save** once the connection is successful.

**Method 2. Republish the dashboards**

The ```publish_templates.py``` script located in the publish folder of this repository can be used to republish the dashboards; this script embeds the account credentials in the workbook on the server. For information on how to publish the dashboards, refer to [Publishing Templates](./publish_templates.md).

### How do I change the SQL queries in the templates during development?

During a development cycle in which new columns are added to a template, it is necessary to manually update the SQL queries in the template to point to the prefixed views (e.g., `DEV_PRODUCTX_*`).

To update the SQL queries in the templates, extract the files from the twbx file as described in [Nexus-6 Dashboard](./productx_dashboard.md), open the XML file in a text editor, and search/replace the following text:

* Search: ```DB.PRODUCTX_BR.NEXUS6```
* Replace: ```DB.PRODUCTX_BR.DEV_PRODUCTX```

Once changes are complete, you must search/replace to revert the text:

* Search: ```DB.PRODUCTX_BR.DEV_PRODUCTX```
* Replace: ```DB.PRODUCTX_BR.NEXUS6```

## Nexus-6 (General)

### What is the minimum number of devices and SRs required to generate a Nexus-6 report?

* The minimum number of devices required to generate a Nexus-6 Prime report is 25.
* The minimum number of SRs required to generate a Nexus-6 Lite report is 50.

**Note:** If the number of devices is < 25 and the number of SRs is < 50 for a given request, a Nexus-6 report will not be generated.

### Is it necessary to run requests manually?

No. With the introduction of [Nexus-6 Automation](./productx_automation.md), manual runs are no longer necessary and are discouraged as running the ETL process manually can conflict with the normal automation process.

If a request needs to be rerun, the status can be set to ```Open```, and the request will be added to the automation queue. As with any request, make sure the appropriate fields (i.e., Customer Identifier and associated ID field) are populated when requeuing a request.

**Note**: Running the ETL process manually can potentially conflict with the preprocessing phase of the automation process and can result in table locks and duplicate runs for the same request. For additional information, see [Can I manually run the automation scripts?](#can-i-manually-run-the-automation-scripts)

## Nexus-6 Automation

### How are requests validated during automation?

For details regarding the validation process, refer to the [High-Level Logic](./productx_automation.md/#high-level-logic) section of the [Validation](./productx_automation.md/#validation-productx_validatorpy) topic.

### How do I check the automation queue?

Currently, the automation queue can be viewed only by querying the view on the Snowflake production environment. 

For production requests, the automation queue is stored in the following view on the Snowflake production environment: ```PRODUCTX_UI_DETAILS_QUEUE```

For development and UAT, the automation queues are stored in the following views:
* ```UAT_PRODUCTX_UI_DETAILS_QUEUE```
* ```DEV_PRODUCTX_UI_DETAILS_QUEUE```

**Note**: The ```PRODUCTX_UI_DETAILS_QUEUE``` view includes only requests that have been validated. To view requests that are pending validation, are validated, or are in progress, you can filter the Nexus-6 UI using the following values in the *Request Status* dropdown field: Open, Validated, In Progress, Empty. A public view (*Automation Queue*) has been created using these filters.

### Can I manually run the automation scripts?

The automation scripts should be run manually **only** during development or user-acceptance testing (UAT) using the appropriate table prefix; for example:

```python productx_validator.py --table-prefix UAT_```

```python productx_preprocessor.py --table-prefix UAT_```

**<span style="color:red">IMPORTANT!</span>** The automation scripts should not be run manually against the production tables (i.e., without the `--table-prefix`) as the following issues can occur:

*  Duplicate runs for the same request ID.

    If the preprocessor script is manually run at the same time the automation process runs, both processes can pick up the same requests from the queue; when this scenario occurs, an incorrect URL can be written to the Nexus-6 because the process that runs first can finish after the second process starts; therefore, the URL written to the Nexus-6 will include an older run ID and the customer-specific data on the Nexus-6 dashboard will be blank.

* Potential for table locks and API errors.

    For more information, see [Why is the preprocessor script limited to processing 5 requests at a time?](#why-is-the-preprocessor-script-limited-to-processing-5-requests-at-a-time)


### How many requests are processed during the automation process?

* During the validation phase, all requests where ```status``` is Open or NULL are extracted from the Nexus-6 and added to the automation queue (depending on validation results). For more information about the validation process, refer to the [Validation](./productx_automation.md/#validation-productx_validatorpy) topic.
* During the preprocessing phase, a maxium of five (5) requests are extracted from the Nexus-6 queue (```PRODUCTX_UI_DETAILS_QUEUE```) and processed every ten (10) minutes.

### Why is the preprocessor script limited to processing 5 requests at a time?

The preprocessor script processes a maximum of 5 requests at a time due to the following:

* Potential for table locks.

    Running ETL workflow processes in addition to the scheduled automation process increases the workload on the Snowflake data sources and can result in table locks due to contention (in which two or more components of the workload are attempting to use a single resource in a conflicting way). When a table is locked, all workflow processes (manual or automated) will be blocked until the deadlock has been resolved (which is typically 2 hours).

* Potential for API errors.

    The Nexus-6 workflow uses several Company APIs that restrict the number of requests allowed per second; as the number of requests being processed increases so does the potential for those APIs returning errors because the maximum number of allowed requests per second is exceeded.

### Are partner requests supported within the automation process?

Partner requests are not supported within the Nexus-6 automation process.

## Additional Resources

* For information regarding how to grant access to projects on the Tableau server (prd or stg) using AD mailer groups, refer to the *BEST PRACTICES* section of CX Tableau - Usage, Policies, Best Practices.
* For information regarding enrollment in the nPRD Duo account (which is required for access to the tableau-stage.company.com server), see Duo MFA for Cisco Workforce.
