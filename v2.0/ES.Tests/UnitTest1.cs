using Xunit;
using ES.Models;

namespace ES.Tests;

public class UnitTest1
{
    [Fact]
    public void Test1()
    {
        var weather = new WeatherForecast();
        weather.TemperatureC = 10;

        Assert.Equal(weather.TemperatureF, 49);
    }
}