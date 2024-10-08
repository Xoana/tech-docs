# Nexus-6 Automation (Validation & Preprocessing)

The Nexus-6 automation validation & preprocessing phases are executed using the following scripts located in the jobs folder of the productx-dashboard GitHub repository:

* ```productx_validator.py```
* ```productx_preprocessor.py```

These scripts are executed cyclically using a Control-M job (`NONEDW_PRODUCTX_AUTOMATION_PREPROCESSOR`) that runs every 30 minutes; for more information regarding the automation job, refer to the *Control-M Jobs* Confluence page.

For answers to frequently asked question, refer to the [Automation](./frequently-asked-questions.md/#automation) section of the [Frequently Asked Questions](./frequently-asked-questions.md) page.

## Validation (```productx_validator.py```)

The validation phase of the automation process is executed using the ```productx_validator.py``` script. This script validates the number of devices and service requests for each request based on Customer IDs and updates the request in the Nexus-6 UI accordingly.

### High-Level Logic

1. Extract all requests from the PRODUCTX_UI_DETAILS table where the following conditions are true:
    * ```status``` is Open or NULL.
    * ```customer_identifier``` (and associated field for values) is not NULL.
    * ```request_type``` is not a partner request.
1. For each request, the following actions are taken:
    1. Extract Customer IDs (based on the list of customer identifiers).
    1. Determine report type.
    1. Determine request status.
    1. Call Nexus-6 API to update the request as follows:

Once a request is marked as *Validated*, it is added to the `PRODUCTX_UI_DETAILS_QUEUE` view to be picked up by the preprocessor script; for more information about the preprocessor script, see [Preprocessing (```productx_preprocessor.py```)](#preprocessing-productx_preprocessorpy).

### File Storage

Log files generated by this script are stored in the following location on the cloud gateway: ```productx > productx-automation-input > logs``` 

The validator log files use the following naming convention: 

```validator_<epoch_time>.log```

## Preprocessing (```productx_preprocessor.py```)

The preprocessing phase of Nexus-6 automation is executed using the ```productx_preprocessor.py``` script. This script extracts a maximum of 5 requests from the automation queue every 10 minutes, generates a yaml input file, and executes the data ETL process.

### High-Level Logic

1. Get available capacity for batch size.

    **Note**: The maximum batch size is 5 requests; however, if additional processes are currently running on the cloud gateway, the batch size will be reduced to 5 minus the number of currently running processes.

1. Extract validated requests from the `PRODUCTX_UI_DETAILS_QUEUE` view based on batch size.
1. Generate the ETL input (yaml) file.
1. Call Nexus-6 API to update the status in the Nexus-6 to *In Progress*.
1. Execute the data ETL script (```run_productx.py```) with the input yaml file.

### File Storage

The ```productx_preprocessor.py``` script stores files in the following locations on the cloud gateway:

* productx > productx-automation-input: yaml input files.
* productx > productx-automation-input > logs: Preprocessor log files.

The preprocessor input and log files use the following naming convention: 

```<epoch_time>.log```

<hr/>

[Return to README](../../README.md)
