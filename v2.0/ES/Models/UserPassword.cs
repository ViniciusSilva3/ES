namespace ES.Models;

public class UserPassword : ValueObject
{
    private readonly string _value;

    public static Result<UserPassword> Create(string password)
    {
        if (String.IsNullOrEmpty(password))
            return Result.Fail<UserPassword>("Password cannot be an empty string.");
        if (password.Length < 6)
            return Result.Fail<UserPassword>("Password must have at least 6 characters.");
        
        return Result<UserPassword>.Ok<UserPassword>(new UserPassword(password));
    }

    protected UserPassword(string value)
    {
        _value = value;
    }

    protected override IEnumerable<object> GetEqualityComponents()
    {
        yield return _value;
    }
    public static implicit operator string(UserPassword password) => password._value;
    public static explicit operator UserPassword(string str) => new UserPassword(str);
}