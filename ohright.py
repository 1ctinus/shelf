import pandas as pd

url_template = "https://www.pro-football-reference.com/teams/nyg/{year}.htm"
# for each year from 1950 to 2017
dataset = []
for year in range(2020, 2021):
    df_list = pd.read_html(url_template.replace("{year}",str(year)), skiprows = 0, header=1, index_col=1)[1]
    dataset.append(df_list)
dataset = pd.concat(dataset)


# export to excel
dataset.to_excel('nyg.xlsx')
