# Create a Python Virtual Environment

This procedure describes how to create a python virtual environment to use when executing the `publish_templates.py` script located in the `src/publish` folder. 

**Note**: This virtual environment should not be used to run the job scripts; the job scripts are intended to be run on the cloud gateway using the productx virtual environment.

1. Install python if it is not already installed; this procedure uses Python 3.10.7.

1. Change to a location on your local machine outside the productx-dashboard repo, and run the following command to create a python virtual environment: 
    
    `python -m venv productx-dashboard-venv`

1. Activate the virtual environment:

    * On Windows: `source productx-dashboard-venv/Scripts/activate`
    * On Mac: `source productx-dashboard-venv/bin/activate`

1. Install the python packages using the [requirements.txt](./requirements.txt) file:

    `pip install -r ../productx-dashboard/docs/requirements.txt`