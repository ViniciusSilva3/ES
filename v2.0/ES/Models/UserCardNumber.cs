namespace ES.Models;
public class UserCardNumber : ValueObject
{
    private readonly string _value;

    public static Result<UserCardNumber> Create(string cardNumber)
    {
        if (String.IsNullOrEmpty(cardNumber))
            return Result.Fail<UserCardNumber>("Card number cannot be an empty string.");

        cardNumber = cardNumber.Trim();
        if (!cardNumber.All(char.IsDigit))
            return Result.Fail<UserCardNumber>("Card number must only contain numbers.");
        if (cardNumber.Length != 10)
            return Result.Fail<UserCardNumber>("Card number must contain 10 digits.");

        return Result.Ok<UserCardNumber>(new UserCardNumber(cardNumber));
    }

    protected UserCardNumber(string value)
    {
        _value = value;
    }

    protected override IEnumerable<object> GetEqualityComponents()
    {
        yield return _value;
    }
    public static implicit operator string(UserCardNumber cardNumber) => cardNumber._value;
    public static explicit operator UserCardNumber(string str) => new UserCardNumber(str);
}