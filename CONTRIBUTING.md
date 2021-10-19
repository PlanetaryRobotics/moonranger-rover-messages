# Guide on how to contribute to this repo

when in doubt, `git status` is your best friend

## Steps for making code change

1. `git checkout main && git pull`, go to main branch and pull latest changes
   
2. `git checkout -b <your-branch>`
   for example: `git checkout -b scratch/kelvin/camera_interface`
   note that all feature development branches should begin with `scratch/` as this is used for the continuous integration system.

3. `git status` and check that you are in the right branch

4. `git branch --set-upstream-to=<remote-main-branch> <your-branch>` for example `git branch --set-upstream-to=origin/main scratch/kelvin/camera_interface`

5. Make your edit, build, test, and format

6. `git status` and you should see your changes in red color

7. `git add -A` to add all the changes, but I suggest you use VS code function to individually select the changes you want

8. `git status` and you should see your changes in green color

9. `git commit` and write a thoughtful commit msg

   for example:

   ```
    [Perception] add save image feature to camera interface app
   
    -Add function in camera_if to save the next image to disk when triggered by CMD_MID
    -Add unit test for the save image function to detect if fail to save to disk
    -Feature is limited to saving raw images, compression to be added
    -Integration with camera driver to be done
   
    Issue: #58 Perception - Save Images
   ```

10. `git commit --amend` if you need to change your latest commit msg

11. `git log` to see that your commit is added, press `q` to exit the log

12. `git pull origin main --rebase` once your branch is getting old and behind the master. This will pull the latest changes in master and apply it to your branch, but your latest commit is on top of the latest master changes

13. `git log` again to see that your commit is still at the top of any new changes

14. Test, test, test

15. `git push origin <your-branch>` for example `git push origin scratch/kelvin/camera_interface`

16. You should see a message in the console like this: `remote: Create a pull request for '<your-branch>' on GitHub by visiting:` and a url link to the pull request

17. Fill out the PR form properly, add screenshots and test results and in-depth comments if necessary

18. It is unlikely that your PR is acceptable the first time, so please see below on how to make changes to your PR

## Making changes to your PR

1. `git pull origin main --rebase` if you want to keep your branch up-to-date with latest main. But you need to do force-push later on (see below)

2. Stay in your branch and make your changes and don't forget to run your tests

3. `git add -A` to add all the changes, but I suggest you use VS code function to individually select the changes you want

4. `git commit` and write a thoughtful commit msg

5. `git log` and you should see your latest commit on top of your previous commit

6. If it doesn't make sense to add more commits (maybe it is a small bug fix) or your commit history for this PR is getting long, use `git rebase -i`. this will bring you to interactive session to squash your commits together. For example you will see smth like this:

   ```
   pick 4def5bb your original commit msg
   pick 9f93f95 fix bug
   
   # Rebase dccd638..9f93f95 onto dccd638 (2 commands)
   #
   ```

   Then use your editor and change all the commits after your first commit msg from `pick` to `f`. So it will look like this:

   ```
   pick 4def5bb your original commit msg
   f 9f93f95 fix bug
   
   # Rebase dccd638..9f93f95 onto dccd638 (2 commands)
   #
   ```

   Remember to save

7. `git log` one more time and you should only see your original commit msg

8. `git commit --amend` in case you want to edit the commit msg to reflect new changes

9. Build, test, test, test

10. `git push origin <your-branch>` again, OR if you have squashed or make changes that is inconsistent with remote, use `git push origin <your-branch> -f` NOTICE THE EXTRA FLAG!! No url will show up this time, go to github to see your latest change. The extra flag is for force push, and will delete all data from the remote server and replace it with your current local git state. Hence, if someone else is editing this PR, check with them first.

## After your PR is merged to master

1. Congratulation, grab a bottle of beer
2. `git checkout main` go back to master branch
3. `git branch -D <your-branch>` to delete your branch, make sure there's no unsaved unchages you do not want to lose
4. Delete the branch in the github server also once you do not need them to keep the Github clean

# Other useful stuff

## File Docstring to be added at the top of files
```C++
/****************************************************************
 * 
 * @file      vc_app.h
 * 
 * @brief     The Vehicle Controller App  header containing definitions for the main app
 * 
 * @version   1.0
 * @date      09/19/2021
 * 
 * @authors   Ben Kolligs, ...
 * @author    Carnegie Mellon University, Planetary Robotics Lab
 * 
 ****************************************************************/
```

## Doxygen style comments for functions/classes
```C++
/**
 * @brief this functions does this and that
 * 
 * This is a more thorough explanation of the class if you need to
 * 
 * @param MyParam1 this param is what, in what units, etc...
 * @param MyParam2 this param is from what, and so on...
 * @return int32 this return represents what...
 * 
 * @note what should a user of this function be careful of...
 */
```

# Read up and learn more about Git

- [Udacity Git Course](https://www.udacity.com/course/version-control-with-git--ud123)
- [Git Rebase](https://www.atlassian.com/git/tutorials/rewriting-history/git-rebase)
- [Git Reset](https://www.atlassian.com/git/tutorials/undoing-changes/git-reset)
