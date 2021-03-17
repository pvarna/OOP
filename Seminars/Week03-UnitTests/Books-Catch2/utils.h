#pragma once

typedef bool (*priceFilter) (double a, double b);

bool isMoreExpensive(double a, double b);

bool isCheaper(double a, double b);