namespace ES.Models;

public class User
{
    public UserCpf Cpf { get; set; }
    public UserCardDate CardDate { get; set; }
    public UserCardDigits CardDigits { get; set; }
    public UserCardNumber CardNumber { get; set; }
    public UserPassword Password { get; set; }

    public User(UserCpf cpf, UserCardDate cardDate, UserCardDigits cardDigits,
        UserCardNumber cardNumber, UserPassword password)
    {
        Cpf = cpf;
        CardDate = cardDate;
        CardDigits = cardDigits;
        CardNumber = cardNumber;
        Password = password;
    }
}
