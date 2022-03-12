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

    private User Create(string cpf, string password, string cardDate, string cardDigits,
        string cardNumber)
    {
        var cpfResult = UserCpf.Create(cpf);

        var cardDateResult = UserCardDate.Create(cardDate);
        var cardDigitResult = UserCardDigits.Create(cardDigits);
        var cardNumberResult = UserCardNumber.Create(cardNumber);
        var passwordResult = UserPassword.Create(password);

        return new User(cpfResult.Value, cardDateResult.Value, 
            cardDigitResult.Value, cardNumberResult.Value, passwordResult.Value);
    }

    private List<User> Parse(string[] users)
    {
        List<User> returnList = new List<User>();
        foreach (string user in users)
        {
            string[] readUser = user.Split(';');
            User tempUser = Create(readUser[0], readUser[1],
                readUser[2], readUser[3], readUser[4]);
            returnList.Add(tempUser);
        }
        return returnList;
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