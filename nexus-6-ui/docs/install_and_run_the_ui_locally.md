# Install and Run the UI Locally<a name="install-and-run-the-ui-locally"></a>

To install and run the UI locally, complete the procedures described in this topic.

## Before You Begin

Set up your local development environment as described in [Set Up Your Local Development Environment](../README.md#set-up-your-local-development-environment).

## Create a Virtual Environment

1. Create a python virtual environment:

	```
	$ python -m venv productx-ui-venv
	```

	**Note**: Do not create the python virtual environment inside a git repository.

1. Activate the venv:
	
	* On Windows, run ```$ source <path_to_venv>/productx-ui-venv/Scripts/activate```.
	* On Mac, run ```$ source <path_to_venv>\x-productx-ui-venv\bin\activate```.
	
1. Run the following command to install dependencies using the [requirements.txt](./requirements.txt) requirements file:

	```
	$ pip install -r <path_to_file>/productx-ui-venv-requirements.txt
	```

1. Change to the `productx-ui-venv` virtual environment folder, and run the following command to install node.js and attach nodeenv to the python venv:
    
	```
	$ nodeenv -p --node=16.13.2
	```

	**Notes**:
	* If received the following error on Windows, you can ignore it:
		```
		Error: Failed to create nodejs.exe link
		```
	* If you receive an SSL error on Mac, run the following command to install certificates: 
	
		```
		open /Applications/Python\ 3.7/Install\ Certificates.command
		``` 

1. With the venv activated, [install the UI](#install-the-ui).

## Install the UI

### Typical Installation

This procedure installs all the Angular packages used in the UI application and can take several minutes to complete.

**<span style="color:red">IMPORTANT!</span>** Do not install the UI within your *OneDrive* folder.

To install the UI, complete these steps:

1. If it is not already cloned, clone this repo:
	
	```
	$ git clone https://www-github3.company.com/cxe/productx-ui.git
	```

	**Note**: Do not clone the repository inside the python virtual environment folder.

1. If it is not already activated, activate the `productx-ui-venv` virtual environment; see [Create a Virtual Environment](#create-a-virtual-environment).
1. Change to the productx-ui folder on your local machine, and delete the **package-lock.json** file.
1. Open a terminal, and run the following command: 
	
	```
	$ npm install --legacy-peer-deps
	```

1. Confirm that the installation was successful by building and serving the UI as described in [Build and Serve the UI](#build-and-serve-the-ui).

**Notes**:
* This procedure must be completed only when the UI is initially installed or when the package.json file changes (which is rare). When the package.json file changes, you must reinstall the UI; to reinstall the UI, delete the **node_modules** folder and the **package-lock.json** file from your local application folder, and run the following command: ```npm 
install --legacy-peer-deps```
* If the installation process fails because it cannot locate the *productx-ng* package (or the *npm.productx.com* registry), refer to the [Alternate Installation](#alternate-installation) for alternate installation instructions. 

### Alternate Installation

This procedure installs the UI without the *productx-ng* package; it should be used only when a typical installation fails to install the *productx-ng* package.

Once you have confirmed that the UI will not install using the typical installation method, complete these steps:

1. Delete the following items:
	* **package.json** file
	* **package-lock.json** file
	* **node_modules** folder
1. Rename **package_alt.json** to **package.json**.
1. Open a terminal, and run the following command: 

	```
	npm install --legacy-peer-deps
	```

1. Once the installation process completes, extract the **@productx-ng.zip** into the *node_modules* folder.
    
    **Note**: The resulting folder hierarchy must be as follows: `node_modules > @company > productx-ng`

1. Confirm that the installation was successful by building and serving the UI as described in [Build and Serve the UI](#build-and-serve-the-ui).

## Build and Serve the UI

To run the UI on your local machine, complete these steps:

1. Open a terminal and change to the productx-ui folder.

1. If it is not already activated, activate the `productx-ui-venv` virtual environment, and run one of the following commands (depending on which version you want to run):

	* Development: ```ng serve --configuration development```
	* Stage: ```ng serve --configuration stage```
	* Production: ```ng serve --configuration production```

		**<span style="color:red">IMPORTANT!</span>** When you build the UI using the production configuration, any changes you make in the UI on localhost will be saved to the production tables.

1. To access the UI locally, open a browser and navigate to http://localhost:4200.

<hr/>

[Return to README](../README.md)
