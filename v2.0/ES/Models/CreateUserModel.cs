namespace ES.Models;

public class CreateUserModel
{
    public string cpf { get; set; }
    public string password { get; set; }
    public string cardNumber { get; set; }
    public string cardDate { get; set; }
    public string cardDigits { get; set; }
}