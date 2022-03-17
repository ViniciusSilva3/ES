using Xunit;
using ES.Db;
using ES.Models;
using ES.Domain.User;
public class UserDatabaseTests
{
    [Fact]
    public void should_create_new_user_if_the_user_does_not_exist()
    {
        var dbClient = new UserDatabaseManager();
        var testUser = new User(
            UserCpf.Create("123456789").Value, 
            UserCardDate.Create("2020-02-01").Value,
            UserCardDigits.Create("123").Value,
            UserCardNumber.Create("0123456789").Value,
            UserPassword.Create("adminpassword").Value);
        var fileContent = new FileContent(new string[] {
            "222222222;password;01/04/2021;444;0123456789;"
        }, "file");

        Maybe<FileOperation> operation = dbClient.AddUser(fileContent, testUser);

        Assert.True(operation.HasValue);
        if (operation.HasValue)
        {
            Assert.Equal(OperationType.WRITE, operation.Value.Type);
            Assert.Equal(new[] {
                "222222222;password;01/04/2021;444;0123456789",
                "123456789;adminpassword;01/02/2020;123;0123456789"
            }, operation.Value.Content);
            Assert.Equal("file", operation.Value.FileName);
        }
    }
    [Fact]
    public void should_return_null_if_creating_already_existing_user()
    {
        var dbClient = new UserDatabaseManager();
        var testUser = new User(
            UserCpf.Create("123456789").Value, 
            UserCardDate.Create("2020-02-01").Value,
            UserCardDigits.Create("123").Value,
            UserCardNumber.Create("0123456789").Value,
            UserPassword.Create("adminpassword").Value);
        var fileContent = new FileContent(new string[] {
            "222222222;password;01/04/2021;444;0123456789;",
            "123456789;adminpassword;01/02/2020;123;0123456789"
        }, "file");

        Maybe<FileOperation> operation = dbClient.AddUser(fileContent, testUser);

        Assert.True(operation.HasNoValue);
    }
}