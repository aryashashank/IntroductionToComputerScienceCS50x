<form action="changePassword.php" method="post">
    <fieldset>
        <div class="form-group">
            <input autocomplete="off" autofocus class="form-control" name="oldPassword" placeholder="Old Password" type="password"/>
        </div>
        <div class="form-group">
            <input class="form-control" name="newPassword" placeholder="New Password" type="password"/>
        </div>
        <div class="form-group">
            <input class="form-control" name="confirmPassword" placeholder="Confirm New Password" type="password"/>
        </div>
        <div class="form-group">
            <button class="btn btn-default" type="submit">
                <span aria-hidden="true" class="glyphicon"></span>
                Submit
            </button>
        </div>
    </fieldset>
</form>
