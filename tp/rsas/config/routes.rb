Rails.application.routes.draw do
	resources :rsas, only: [:show, :create]
end
