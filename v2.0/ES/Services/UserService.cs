using ES.Db;
using ES.Models;
using ES.Constants;
namespace ES.Services;

public interface IUserService
{
    Result CreateUser(User user);
}

public class UserService : IUserService
{
    private readonly IUserDatabaseManager _userDatabaseManager;
    private readonly IPersister _persister;

    public UserService(IPersister persister, IUserDatabaseManager userDatabaseManager)
    {
        _userDatabaseManager = userDatabaseManager;
        _persister = persister;
    }

    public Result CreateUser(User user)
    {
        FileContent content = _persister.ReadFileContent(DbConstants.userFileName);

        Maybe<FileOperation> createUserOperation = _userDatabaseManager.AddUser(content, user);

        if (createUserOperation.HasValue)
        {
            _persister.ApplyChanges(createUserOperation.Value);
            return Result.Ok();
        }
        
        return Result.Fail("User already exists.");
    }
}
