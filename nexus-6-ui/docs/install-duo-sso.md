# Install duo-sso

This procedure describes how to install duo-sso on Windows.

## Before You Begin

Set up your local development environment as described in [Set Up Your Local Development Environment](../README.md#set-up-your-local-development-environment).

## Procedure

1. Create a folder in the productx-ui folder directory named _duo-sso_.
1. In the duo-sso folder, create a new file named _config.json_, and paste the following code:

	```
	{
		"url": "https://cloudsso.productx.com",
		"preferred_factor": "push",
		"partner_spid": "https://signin.aws.amazon.com/saml",
		"aws_urn": "https://signin.aws.amazon.com/saml",
		"session_duration_seconds": 900,
		"profiles": {
			"default": {
			"aws_account_id": 123456789123,
			"aws_role_name": "AWS-PRODUCTXCloud-Admin",
			"session_duration_seconds": 900
			},    
			"stage": {
			"aws_account_id": 123456789123,
			"aws_role_name": "admin",
			"session_duration_seconds": 900
			},
			"production": {
			"aws_account_id": 123456789123,
			"aws_role_name": "admin",
			"session_duration_seconds": 900
			}    
		}
	}
	```
1. Change the ```aws_account_id``` values for each environment to the appropriate ID. 
	
	Contact a member of the development team for the appropriate account IDs for the UI.

	**Note**: You can also view these values on the AWS environment: Log into the AWS Management Console, and click the drop-down arrow next to your email address. The values are listed in the drop-down as follows:
	* Federated Login: ```aws_role_name```/username@company.com
	* My Account: ```aws_account_id```
	
1. Download the duo-sso utility and save it to the duo-sso folder.