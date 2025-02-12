# Nexus-6 Release Process

This topic describes how to deploy the Nexus-6 UI to AWS; these procedures are to be completed by the Development team only.

## Before You Begin

Set up your local development environment as described in [Set Up Your Local Development Environment](../README.md#set-up-your-local-development-environment).

## Release Preparation
1. Use gitflow to start and finish a release branch (specifying the appropriate release number as the tag).
1. Push changes to develop and master branches.
1. Add release notes to the GitHub tag.

## Deployment Procedure

Complete the following steps to deploy the Nexus-6 UI:

1. Within your local `productx-ui repo`, check out the `master` branch.
1. Activate the `productx-ui-venv` virtual environment.

    For information on how to create the `productx-ui-venv` virtual environment, refer to [Create a Virtual Environment](./docs/install_and_run_the_ui_locally.md#create-a-virtual-environment).

1. Run the ```build-deploy.py``` script:

    * For the UAT release, run the following command:

        ```python build-deploy.py --configuration stage```

    * For the production release: 

        Run this command to block the UI before the deployment begins:

        ```python build-deploy.py --configuration production --block-ui```

        Run this command to unblock the UI after the deployment is complete: 

        ```python build-deploy.py --configuration production```

        **Note**: The UI is blocked to prevent users from using the Nexus-6 while database changes are being made; therefore, it is not necessary to block the UI if only UI changes are being deployed.

For more information about deploying the UI, see [Build and Deploy the UI](./docs/build_and_deploy_ui.md).

<hr/>

[Return to README](../README.md)