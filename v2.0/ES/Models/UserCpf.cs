namespace ES.Models;
public class UserCpf : ValueObject {
    private readonly string _value;

    private UserCpf(string value)
    {
        _value = value;
    }
    public static Result<UserCpf> Create(string userCpf)
    {
        if(String.IsNullOrEmpty(userCpf))
            return Result.Fail<UserCpf>("cpf cannot be empty.");

        userCpf = userCpf.Trim();
        if(userCpf.Length > 9)
            return Result.Fail<UserCpf>("cpf can only contain 9 digits.");

        if(!userCpf.All(char.IsDigit))
            return Result.Fail<UserCpf>("cpf can only contain numbers.");
        
        return Result.Ok<UserCpf>(new UserCpf(userCpf));
    
    }
    protected override IEnumerable<object> GetEqualityComponents()
    {
        yield return _value;
    }
    public static implicit operator string(UserCpf cpf) => cpf._value;
    public static explicit operator UserCpf(string str) => new UserCpf(str);
}