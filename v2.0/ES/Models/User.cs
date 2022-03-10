namespace ES.Models;

public class User
{
    public UserCpf _cpf { get; set; }
    public UserCardDate _cardDate { get; set; }
    public UserCardDigits _cardDigits { get; set; }
    public UserCardNumber _cardNumber { get; set; }
    public UserPassword _password { get; set; }

    public User(UserCpf cpf, UserCardDate cardDate, UserCardDigits cardDigits,
        UserCardNumber cardNumber, UserPassword password)
    {
        _cpf = cpf;
        _cardDate = cardDate;
        _cardDigits = cardDigits;
        _cardNumber = cardNumber;
        _password = password;
    }
}
