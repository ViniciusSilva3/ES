using ES.Db;
using ES.Models;
using ES.Constants;
using ES.Domain.User;
namespace ES.Services;

public interface IUserService
{
    Result CreateUser(User user);
    Result<User> GetUser(UserCpf userCpf);
    Result<List<User>> GetAllUsers();
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

    public Result<User> GetUser(UserCpf userCpf)
    {
        FileContent content = _persister.ReadFileContent(DbConstants.userFileName);

        Maybe<User> user = _userDatabaseManager.GetUser(content, userCpf);

        if (user.HasValue)
        {  
            return Result.Ok(user.Value);
        }

        return Result.Fail<User>($"User with CPF: {(string)userCpf} does not exist.");
    }

    public Result<List<User>> GetAllUsers()
    {
        FileContent content = _persister.ReadFileContent(DbConstants.userFileName);

        Maybe<List<User>> userList = _userDatabaseManager.GetAllUsers(content);

        if (userList.HasValue)
        {  
            return Result.Ok(userList.Value);
        }

        return  Result.Fail<List<User>>("There are no users registred!");
    }
}
