# Nexus-6 Compare Dashboard

## Overview

The Nexus-6 Compare dashboard allows internal users to compare different runs for a single request or across multiple requests.

## Data Sources

The Nexus-6 Compare dashboard uses the ```PRODUCTX_COMPARE``` view located on the Snowflake BR layer.

## Updating the Template

The Nexus-6 Compare dashboard is generated using the ```productx_compare.twbx``` file.

After making changes to this file, ensure that the search field is empty before publishing.

**Note**: This dashboard is currently for internal use only.

## Publishing the Template

Run the following command from the _publish_ folder in this repo:

```python publish_templates.py --template-to-publish productx_compare.twbx```

**Note**: To publish to the Dev or UAT projects on the Tableau server, include the appropriate ```--env``` and ```--table-prefix``` values to the command; for example:

```python publish_templates.py --template-to-publish productx_compare.twbx --env dev --table-prefix DEV_```

For more information about publishing Nexus-6 dashboards, refer to [Publishing Templates](./publish_templates.md).

<hr/>

[Return to README](../../README.md)