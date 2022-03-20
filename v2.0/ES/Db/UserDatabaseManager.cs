namespace ES.Db;
using Models;

public interface IUserDatabaseManager
{
    Maybe<FileOperation> AddUser(FileContent currentFile, User newUser);
}
public class UserDatabaseManager : IUserDatabaseManager
{ 
    // pertence a casca escolher a operacao
    public UserDatabaseManager()
    {
    }

    public Maybe<FileOperation> AddUser(FileContent currentFile, User newUser)
    {
        List<User> users = Parse(currentFile.Content);

        var user = users.FirstOrDefault(user => user.Cpf == newUser.Cpf);
        if (user != null)
            return null;

        users.Add(newUser);
        return new FileOperation(Serialize(users), currentFile.FileName, OperationType.WRITE);
    }

    private List<User> Parse(string[] users)
    {
        List<User> returnList = new List<User>();
        foreach (string user in users)
        {
            string[] readUser = user.Split(';');
            Maybe<User> tempUser = Create(readUser[0], readUser[1],
                readUser[2], readUser[3], readUser[4]);
            if (tempUser.HasValue)
                returnList.Add(tempUser.Value);
        }
        return returnList;
    }

    private Maybe<User> Create(string cpf, string password, string cardDate, string cardDigits,
        string cardNumber)
    {
        Result<UserCpf> Cpf = UserCpf.Create(cpf);
        Result<UserPassword> Password = UserPassword.Create(password);
        Result<UserCardNumber> CardNumber = UserCardNumber.Create(cardNumber);
        Result<UserCardDigits> CardDigits = UserCardDigits.Create(cardDigits);
        Result<UserCardDate> CardDate = UserCardDate.Create(cardDate);

        Result result = Result.Combine(Cpf, Password, CardDate, CardDigits, CardNumber);

        if (result.IsNotSuccess)
            return null!;

        return new User(Cpf.Value, CardDate.Value, 
            CardDigits.Value, CardNumber.Value, Password.Value);
    }
    
    private string[] Serialize(List<User> users)
    {
        return users
            .Select(user => (string)user.Cpf + ';' +
                            (string)user.Password + ';' +
                            (string)user.CardDate + ';' +
                            (string)user.CardDigits + ';' +
                            (string)user.CardNumber)
            .ToArray();
    }
}