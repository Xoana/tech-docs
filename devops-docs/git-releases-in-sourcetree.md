# How to prepare releases using gitflow and Sourcetree

1. Check out master and pull latest.
2. Check out develop and pull latest.
3. While on develop branch, click the Git-flow button, and select Start New Release.
4. In the Feature Name field, enter the release version (e.g., 1.5), and click OK.
5. Once the release is created, click the Git-flow button, and select Finish Release. 
6. Enter the release version again in the tag field, and leave Delete branch selected.
(NOTE: You must delete the release branch or you won't be able to create new releases in the future.)
Once the release process is finished, the develop branch should be checked out by default, and Sourcetree should show that you need to push changes to develop and master.
7. On the develop branch, push changes.
8. Checkout master and push changes.
9. To add release notes, go to the repository on github.com, click tags, click the tag you just added, and click Edit release.
