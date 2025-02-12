# Nexus-6 Dashboard

## Overview

The Nexus-6 3.0 dashboard provides data insights into customer networks and is accessed using a single URL. 

## Modifying the Template

The Nexus-6 3.0 dashboard is generated using the `nexus_template.twbx` file (located in the *templates* folder).

**Important Note!** Changes cannot be made to Tableau templates in two different branches at the same time (because there is no way to merge changes within a .twbx file).

Typically, the template files can be modified by opening the .twbx file and making changes; however, if the update depends on database changes (e.g., adding a new column), the SQL queries within the twb file will need to be updated to point to the appropriate prefixed views.

To make changes using prefixed views, complete these steps:

1. Copy the template(s) to a location outside your local repo.
1. Change the file extension from .twbx to .zip, and extract the .zip file.
1. Open the .twb file in a text editor, and change the view names to point to the prefixed views; e.g., change ```DB.PRODUCTX_BR.``` to ```DB.PRODUCTX_BR.DEV_```
1. Open the .twb file in Tableau desktop, and make the necessary changes.
1. Save and close the .twb file.
1. Open the .twb file in text editor, and complete these steps: 

    1. Search & replace fully qualified paths to the Image folders; i.e., remove everything before ```Image/```.
    1. Remove the prefix that was previously added to the view names; e.g., change ```DB.PRODUCTX_BR.DEV_``` to ```DB.PRODUCTX_BR.```.

1. Save and close the .twb file.
1. Zip the Image folder (if applicable) and the .twb file. (Ensure the name of the .zip file is the same as the original template.)
1. Change extension from .zip to .twbx.
1. Copy the template file(s) into the template folder within your git branch.
1. Run the ```publish_templates.py``` script to publish the template(s) to the Tableau Dev project; for more information about publishing the templates, refer to [Publishing Templates](./docs/publish_templates.md). 
1. Verify your changes.
1. Once your changes are complete, commit the file(s), and submit a pull request.

<hr/>

[Return to README](../../README.md)