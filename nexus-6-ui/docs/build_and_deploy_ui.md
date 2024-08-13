# Build and Deploy the UI 

The Nexus-6 UI is built and deployed using the `build-deploy.py` script located in the productx-ui repository.

## High-Level Script Logic

The high-level logic for this script is as follows:

1. Verify the user is authenticated; if the user is not authenticated, run the duo-sso utility.
1. Run ```git describe``` to retrieve git version number and add it to the version.ts environment file.

	**Note**: The git version is displayed on the UI beneath the pagination drop-down as follows: ```Application Version: 1.15```

1. Build the UI based on the specified environment.
1. Deploy the UI to AWS based on the specified environment.

## Before You Begin

1. Set up your local development environment as described in [Set Up Your Local Development Environment](../README.md#set-up-your-local-development-environment).
1. Install duo-sso as described in [Install duo-sso](./install-duo-sso.md).

## Running the build-deploy.py Script

Complete these steps to deploy the UI to AWS:

1. If it is not already activated, activate the `productx-ui-venv` virtual environment; for more information, refer to [Create a Virtual Environment](./install_and_run_the_ui_locally.md#create-a-virtual-environment).
1. Open a terminal and navigate to the productx-ui folder.

	**Note**: For UAT and Production releases, the deployment script should be run from the master branch.

1. Run the following command with the ```--env``` option to specify the AWS environment to which the UI should be deployed:

	```python build-deploy.py --env [development|stage|production]```

	For example, ```python build-deploy.py --env development```

	**Note**: To block users from using the UI during a deployment, use the ```--block-ui``` option. This option will display a message on the UI indicating that an update is in progress. 

1. Once the deployment script completes, run the following command to restore the ```version.ts``` file to the committed version:
	
    ```
    git restore .\src\environments\version.ts
    ```
	
	**Note**: During the build process, the contents of ```version.ts``` are replaced. Changes to this file should not be committed to the git repo.

## Additional Build Script Options

To view additional options, run the following command:

```
$ python build-deploy.py --help

Usage: build-deploy.py [OPTIONS]

Options:
  --duo-sso-path TEXT  Path to the duo_sso application; config.json must be
                       located in the same folder.  [default: ./duo-sso]
  --env TEXT           Environment to build: dev, stage, or production.
                       [default: dev]
  --block-ui           Flag to block UI access during deployments.					   
  --skip-auth          Flag to skip authentication.
  --skip-build         Flag to skip building the UI.
  --skip-deploy        Flag to skip deploying to AWS.
  --help               Show this message and exit.
```

<hr/>

[Return to README](../README.md)