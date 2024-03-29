namespace ES.Models;
public class Result
{
    public bool IsSuccess {get; }
    public string Error { get; }
    public bool IsNotSuccess => !IsSuccess;

    protected Result(bool isSuccess, string error)
    {
        // result cannot be success and contain an error message
        if (isSuccess && error != string.Empty)
            throw new InvalidOperationException();
        // result cannot be a failure and contain no error message
        if (!isSuccess && error == string.Empty)
            throw new InvalidOperationException();
        
        IsSuccess = isSuccess;
        Error = error;
    }

    public static Result Fail(string message)
    {
        return new Result(false, message);
    }

    public static Result<T> Fail<T>(string message)
    {
        return new Result<T>(default(T), false, message);
    }

    public static Result Ok()
    {
        return new Result(true, string.Empty);
    }

    public static Result<T> Ok<T>(T value)
    {
        return new Result<T>(value, true, string.Empty);
    }

    public static Result Combine(params Result[] results)
    {
        foreach (Result result in results)
        {
            if (result.IsNotSuccess)
            {
                return result;
            }
        }

        return new Result(true, "");
    }
    
}
public class Result<T> : Result
{
    private readonly T _value;
    public T Value
    {
        get
        {
            if(IsNotSuccess)
                throw new InvalidOperationException();
            
            return _value;
        }
    }
    protected internal Result(T value, bool isSuccess, string error)
        : base(isSuccess, error)
    {
        _value = value;
    }
}