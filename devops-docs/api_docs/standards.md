# API Documentation Standards

Resources:
* [Best Practices in API Documentation | Swagger](https://swagger.io/blog/api-documentation/best-practices-in-api-documentation/)
* [API documentation | Postman](https://www.postman.com/api-platform/api-documentation/)
* [Best Practices for API Docs | Postman](https://www.postman.com/templates/tags/19/Documentation)
* [Documenting APIs: A guide for technical writers and engineers | idratherbewriting](https://idratherbewriting.com/learnapidoc/)
* [Best API docs you’ve seen | Reddit](https://www.reddit.com/r/technicalwriting/comments/1e61mkd/best_api_docs_youve_seen/)

**Note**: According to other writers on Reddit, [Stripe](https://docs.stripe.com/api) is considered one of the best.

# Best Practices

* Provide clear and concise explanations.
* Include code examples: Help developers understand how to use your API by providing code examples in multiple programming languages. These examples should demonstrate how to make requests, handle responses, and include any necessary headers or parameters.
* Document error handlings.
* Include interactive features: If possible, provide interactive features like an API console or playground that allows developers to make requests and see responses in real-time. This can greatly aid understanding and experimentation.
* Keep documentation up to date.

Source: [Postman](https://www.postman.com/templates/e9c28f47-1253-44af-a2f3-20dce4da1f18/API-documentation)

## Structure

* Introduction
* Authentication
* Resources/Endpoints
* Error Messages
* Terms of Use
* Change Log

**Note**: Swagger suggests _Error Messages_ before _Resources_, but I think Error Messages can be used as a reference, so I would add after.

## Resource Structure

* Title (if desired): Brief description; 'Get a list of books'
* Description: Detailed description.
* Sample URI/URL
* Request Parameters
* Response Parameters
* Possible Error Codes
* Sample Code (if desired)

## Conventions

## Resource Descriptions & Titles

* Should begin with a verb; do not add 'the' to all.
* Parameters sections should include parameter, _datatype_, whether it is required, and a description of the parameters with examples. 



## Text Substitution 

Text substitution can be indicated using a variety of special characters. The key is to specify in you documentation which character is used and use it consistently.

[Stack Exchange](https://writing.stackexchange.com/questions/33545/what-are-standard-techniques-that-indicate-to-the-documentation-reader-that-they) provides the followijng suggestions.

* At the beginning of your guide, provide an instruction on how you'll be referencing commands, user-specified text/options, etc. Italic is common for this. For example: text indicates text that you need to provide and should represent actual data, such as your email address, username, password, etc.
* Use consistent formatting options, capitalization, and syntax across your docs.
* Use a common special character to surround user input, such as the already suggested %, <> braces, or [] braces (although I've seen these as marking optional input). Make it explicitly clear if the special characters should be included in the input or not.
* Use a consistent way to reference common user inputs (placeholders) such as "my-user-name", "my-password", "my-email@domain.com", or "". Make sure these are defined with examples at the beginning of your guide.

**Note**: [Bitly](https://dev.bitly.com/docs/getting-started/authentication) uses curly braces.